#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "geo_commands_leek.h"
#include "make_const_nonconst.h"

#define LIGHT_X 0x28
#define LIGHT_Y 0x28
#define LIGHT_Z 0x28

// 0x0700E440 - 0x0700E458
static const Lights1 wf_seg7_lights_0700E440 = gdSPDefLights1(
    255/4, 255/4, 255/4,
    0xff, 0xff, 0xff, LIGHT_X, LIGHT_Y, LIGHT_Z
);

// 0x07001000 - 0x07001800
ALIGNED8 const u8 wf_seg7_texture_plankeyes[] = {
#include "plank_eyes_custom.rgba16.inc"
};

ALIGNED8 const u8 wf_seg7_texture_plankbody[] = {
#include "plank_body_custom.rgba16.inc"
};

// 0x0700E458 - 0x0700E548
static const Vtx wf_seg7_vertex_0700E458[] = {
    {{{   768,   -127,      0}, 0, {   582,    478}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   768,      0,   -101}, 0, {   172,      0}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   768,      0,    102}, 0, {   990,      0}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{     0,      0,    205}, 0, {   990,      0}, {0x25, 0x99, 0x3f, 0xff}}},
    {{{     0,   -127,      0}, 0, {   990,    990}, {0x25, 0x99, 0x3f, 0xff}}},
    {{{   177,      0,    102}, 0, {  1876,    478}, {0x25, 0x99, 0x3f, 0xff}}},
    {{{  -176,      0,    102}, 0, {   104,    478}, {0xdb, 0x99, 0x3f, 0xff}}},
    {{{     0,   -127,      0}, 0, {   990,    990}, {0xdb, 0x99, 0x3f, 0xff}}},
    {{{     0,      0,    205}, 0, {   990,      0}, {0xdb, 0x99, 0x3f, 0xff}}},
    {{{  -176,      0,   -101}, 0, {   104,   1498}, {0xb6, 0x9a, 0x00, 0xff}}},
    {{{     0,   -127,      0}, 0, {   990,    990}, {0xb6, 0x9a, 0x00, 0xff}}},
    {{{  -176,      0,    102}, 0, {   104,    478}, {0xb6, 0x9a, 0x00, 0xff}}},
    {{{     0,      0,   -204}, 0, {   990,   2010}, {0xdb, 0x99, 0xc0, 0xff}}},
    {{{     0,   -127,      0}, 0, {   990,    990}, {0xdb, 0x99, 0xc0, 0xff}}},
    {{{  -176,      0,   -101}, 0, {   104,   1498}, {0xdb, 0x99, 0xc0, 0xff}}},
};

// 0x0700E548 - 0x0700E638
static const Vtx wf_seg7_vertex_0700E548[] = {
    {{{   177,      0,   -101}, 0, {  1876,   1500}, {0x25, 0x99, 0xc0, 0xff}}},
    {{{     0,   -127,      0}, 0, {   990,    990}, {0x25, 0x99, 0xc0, 0xff}}},
    {{{     0,      0,   -204}, 0, {   990,   2010}, {0x25, 0x99, 0xc0, 0xff}}},
    {{{     0,   -127,      0}, 0, {   990,    990}, {0x00, 0xb1, 0x63, 0xff}}},
    {{{   768,   -127,      0}, 0, {  4822,    990}, {0x00, 0xb1, 0x63, 0xff}}},
    {{{   768,      0,    102}, 0, {  4822,    478}, {0x00, 0xb1, 0x63, 0xff}}},
    {{{   177,      0,    102}, 0, {  1876,    480}, {0x00, 0xb1, 0x63, 0xff}}},
    {{{   768,   -127,      0}, 0, {  4822,    990}, {0x00, 0xb1, 0x9d, 0xff}}},
    {{{     0,   -127,      0}, 0, {   990,    990}, {0x00, 0xb1, 0x9d, 0xff}}},
    {{{   177,      0,   -101}, 0, {  1876,   1500}, {0x00, 0xb1, 0x9d, 0xff}}},
    {{{   768,      0,   -101}, 0, {  4822,   1498}, {0x00, 0xb1, 0x9d, 0xff}}},
    {{{   177,      0,   -101}, 0, {   922,    224}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   177,      0,    102}, 0, {   922,    734}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   768,      0,    102}, 0, {  2396,    734}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   768,      0,   -101}, 0, {  2396,    224}, {0x00, 0x7f, 0x00, 0xff}}},
};

// 0x0700E638 - 0x0700E698
static const Vtx wf_seg7_vertex_0700E638[] = {
    {{{     0,      0,   -204}, 0, {   478,      0}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{     0,      0,    205}, 0, {   480,    990}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   177,      0,    102}, 0, {   922,    734}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -176,      0,   -101}, 0, {    36,    224}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -176,      0,    102}, 0, {    36,    734}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   177,      0,   -101}, 0, {   922,    224}, {0x00, 0x7f, 0x00, 0xff}}},
};

// 0x0700E638 - 0x0700E698
static const Vtx wf_seg7_vertex_plnkeyes[] = {
    {{{   177,      1,    177}, 0, {   990,      0}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -176,      1,   -176}, 0, {     0,    990}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -176,      1,    177}, 0, {   990,    990}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   177,      1,   -176}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0xff}}},
};
static const Gfx wf_seg7_dl_0700E698[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, wf_seg7_texture_plankbody),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&wf_seg7_lights_0700E440.l, 1),
    gsSPLight(&wf_seg7_lights_0700E440.a, 2),
    gsSPVertex(wf_seg7_vertex_0700E458, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  7,  8, 0x0,  9, 10, 11, 0x0),
    gsSP1Triangle(12, 13, 14, 0x0),
    gsSPVertex(wf_seg7_vertex_0700E548, 15, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  5, 0x0),
    gsSP2Triangles( 6,  3,  5, 0x0,  7,  8,  9, 0x0),
    gsSP2Triangles(10,  7,  9, 0x0, 11, 12, 13, 0x0),
    gsSP1Triangle(11, 13, 14, 0x0),
    gsSPVertex(wf_seg7_vertex_0700E638, 6, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  4, 0x0),
    gsSP2Triangles( 0,  4,  1, 0x0,  0,  2,  5, 0x0),
    gsSPEndDisplayList(),
};

// 0x0700E760 - 0x0700E7D0
const Gfx wf_seg7_dl_0700E760[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(wf_seg7_dl_0700E698),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

// 0x0700E698 - 0x0700E760
const Gfx wf_seg7_dl_plankeyes[] = {
	// init
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
	// dl
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, wf_seg7_texture_plankeyes),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&wf_seg7_lights_0700E440.l, 1),
    gsSPLight(&wf_seg7_lights_0700E440.a, 2),
    gsSPVertex(wf_seg7_vertex_plnkeyes, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3, 1, 0x0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
	// cleanup
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};




// 0x0700E7E8 - 0x0700E8E8
static const Vtx wf_seg7_vertex_0700E7E8[] = {
    {{{   177,      0,   -101}, 0, {   922,    224}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   177,      0,    102}, 0, {   922,    734}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   768,      0,    102}, 0, {  2396,    734}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   768,      0,   -101}, 0, {  2396,    224}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -176,      0,    102}, 0, {  3940,    990}, {0x00, 0x81, 0x00, 0xff}}},
    {{{     0,      0,   -204}, 0, {  3232,   -236}, {0x00, 0x81, 0x00, 0xff}}},
    {{{   177,      0,   -101}, 0, {  2522,    172}, {0x00, 0x81, 0x00, 0xff}}},
    {{{   177,      0,    102}, 0, {  2522,    990}, {0x00, 0x81, 0x00, 0xff}}},
    {{{     0,      0,    205}, 0, {  3232,   1396}, {0x00, 0x81, 0x00, 0xff}}},
    {{{  -176,      0,   -101}, 0, {  3940,    172}, {0x00, 0x81, 0x00, 0xff}}},
    {{{   768,      0,   -101}, 0, {   166,    172}, {0x00, 0x81, 0x00, 0xff}}},
    {{{   768,      0,    102}, 0, {   166,    990}, {0x00, 0x81, 0x00, 0xff}}},
    {{{   177,      0,    102}, 0, {  2524,    990}, {0x00, 0x81, 0x00, 0xff}}},
    {{{     0,      0,   -204}, 0, {   478,      0}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -176,      0,    102}, 0, {    36,    734}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{     0,      0,    205}, 0, {   480,    990}, {0x00, 0x7f, 0x00, 0xff}}},
};

// 0x0700E8E8 - 0x0700E918
static const Vtx wf_seg7_vertex_0700E8E8[] = {
    {{{     0,      0,   -204}, 0, {   478,      0}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -176,      0,   -101}, 0, {    36,    224}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -176,      0,    102}, 0, {    36,    734}, {0x00, 0x7f, 0x00, 0xff}}},
};

// 0x0700E918 - 0x0700E9B8
static const Gfx wf_seg7_dl_0700E918[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, wf_seg7_texture_plankbody),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&wf_seg7_lights_0700E440.l, 1),
    gsSPLight(&wf_seg7_lights_0700E440.a, 2),
    gsSPVertex(wf_seg7_vertex_0700E7E8, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  4,  6,  7, 0x0),
    gsSP2Triangles( 4,  7,  8, 0x0,  4,  9,  5, 0x0),
    gsSP2Triangles(10, 11, 12, 0x0, 10, 12,  6, 0x0),
    gsSP2Triangles(13,  1,  0, 0x0, 13, 14, 15, 0x0),
    gsSP1Triangle(13, 15,  1, 0x0),
    gsSPVertex(wf_seg7_vertex_0700E8E8, 3, 0),
    gsSP1Triangle( 0,  1,  2, 0x0),
    gsSPEndDisplayList(),
};

// 0x0700E9B8 - 0x0700EA28
const Gfx wf_seg7_dl_0700E9B8[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(wf_seg7_dl_0700E918),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};
