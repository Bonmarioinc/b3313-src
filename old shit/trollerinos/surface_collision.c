#include <PR/ultratypes.h>

#include "sm64.h"
#include "game/debug.h"
#include "game/level_update.h"
#include "game/mario.h"
#include "game/object_list_processor.h"


struct WallCollisionData {
    /*0x00*/ f32 x, y, z;
    /*0x0C*/ f32 offsetY;
    /*0x10*/ f32 radius;
    /*0x14*/ u8 filler[2];
    /*0x16*/ s16 numWalls;
    /*0x18*/ struct Surface *walls[4];
};

struct SurfaceNode {
    struct SurfaceNode *next;
    struct Surface *surface;
};



s32 find_wall_collisions_from_list(struct SurfaceNode *surfaceNode,
                                          struct WallCollisionData *data) {
    register struct Surface *surf;
    register f32 offset;
    register f32 radius = data->radius / 4.0f;
    register f32 x = data->x / 4.0f;
    register f32 y = (data->y + data->offsetY) / 4.0f;
    register f32 z = data->z / 4.0f;
    register f32 px, pz;
    register f32 w1, w2, w3;
    register f32 y1, y2, y3;
    s32 numCols = 0;

    // Max collision radius = 200
    if (radius > 200.0f) {
        radius = 200.0f;
    }

    // Stay in this loop until out of walls.
    while (surfaceNode != NULL) {
        surf = surfaceNode->surface;
        surfaceNode = surfaceNode->next;

        // Exclude a large number of walls immediately to optimize.
        if (y < surf->lowerY || y > surf->upperY) {
            continue;
        }

        offset = surf->normal.x * x + surf->normal.y * y + surf->normal.z * z + surf->originOffset;

        if (offset < -radius || offset > radius) {
            continue;
        }

        px = x;
        pz = z;

        //! (Quantum Tunneling) Due to issues with the vertices walls choose and
        //  the fact they are floating point, certain floating point positions
        //  along the seam of two walls may collide with neither wall or both walls.
        if (surf->flags & SURFACE_FLAG_X_PROJECTION) {
            w1 = -surf->vertex1[2];            w2 = -surf->vertex2[2];            w3 = -surf->vertex3[2];
            y1 = surf->vertex1[1];            y2 = surf->vertex2[1];            y3 = surf->vertex3[1];

            if (surf->normal.x > 0.0f) {
                if ((y1 - y) * (w2 - w1) - (w1 - -pz) * (y2 - y1) > 0.0f) {
                    continue;
                }
                if ((y2 - y) * (w3 - w2) - (w2 - -pz) * (y3 - y2) > 0.0f) {
                    continue;
                }
                if ((y3 - y) * (w1 - w3) - (w3 - -pz) * (y1 - y3) > 0.0f) {
                    continue;
                }
            } else {
                if ((y1 - y) * (w2 - w1) - (w1 - -pz) * (y2 - y1) < 0.0f) {
                    continue;
                }
                if ((y2 - y) * (w3 - w2) - (w2 - -pz) * (y3 - y2) < 0.0f) {
                    continue;
                }
                if ((y3 - y) * (w1 - w3) - (w3 - -pz) * (y1 - y3) < 0.0f) {
                    continue;
                }
            }
        } else {
            w1 = surf->vertex1[0];            w2 = surf->vertex2[0];            w3 = surf->vertex3[0];
            y1 = surf->vertex1[1];            y2 = surf->vertex2[1];            y3 = surf->vertex3[1];

            if (surf->normal.z > 0.0f) {
                if ((y1 - y) * (w2 - w1) - (w1 - px) * (y2 - y1) > 0.0f) {
                    continue;
                }
                if ((y2 - y) * (w3 - w2) - (w2 - px) * (y3 - y2) > 0.0f) {
                    continue;
                }
                if ((y3 - y) * (w1 - w3) - (w3 - px) * (y1 - y3) > 0.0f) {
                    continue;
                }
            } else {
                if ((y1 - y) * (w2 - w1) - (w1 - px) * (y2 - y1) < 0.0f) {
                    continue;
                }
                if ((y2 - y) * (w3 - w2) - (w2 - px) * (y3 - y2) < 0.0f) {
                    continue;
                }
                if ((y3 - y) * (w1 - w3) - (w3 - px) * (y1 - y3) < 0.0f) {
                    continue;
                }
            }
        }

        // Determine if checking for the camera or not.
        if (gCheckingSurfaceCollisionsForCamera) {
            if (surf->flags & SURFACE_FLAG_NO_CAM_COLLISION) {
                continue;
            }
        } else {
            // Ignore camera only surfaces.
            if (surf->type == SURFACE_CAMERA_BOUNDARY) {
                continue;
            }

            // If an object can pass through a vanish cap wall, pass through.
            if (surf->type == SURFACE_VANISH_CAP_WALLS) {
                // If an object can pass through a vanish cap wall, pass through.
                if (gCurrentObject != NULL
                    && (gCurrentObject->activeFlags & ACTIVE_FLAG_MOVE_THROUGH_GRATE)) {
                    continue;
                }

                // If Mario has a vanish cap, pass through the vanish cap wall.
                if (gCurrentObject != NULL && gCurrentObject == gMarioObject
                    && (gMarioState->flags & MARIO_VANISH_CAP)) {
                    continue;
                }
            }
        }

        //! (Wall Overlaps) Because this doesn't update the x and z local variables,
        //  multiple walls can push mario more than is required.
        data->x += surf->normal.x * (radius - offset);
        data->z += surf->normal.z * (radius - offset);

        //! (Unreferenced Walls) Since this only returns the first four walls,
        //  this can lead to wall interaction being missed. Typically unreferenced walls
        //  come from only using one wall, however.
        if (data->numWalls < 4) {
            data->walls[data->numWalls++] = surf;
        }

        numCols++;
    }

    return numCols;
}
