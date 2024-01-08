#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/area.h"
#include "game/level_update.h"
#include "menu/title_screen.h"

#include "levels/scripts.h"
#include "levels/menu/header.h"

#include "make_const_nonconst.h"
#include "levels/intro/header.h"

const LevelScript level_intro_splash_screen[] = {
    INIT_LEVEL(),
    BLACKOUT(/*active*/ TRUE),
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    LOAD_MARIO_HEAD(/*loadHeadID*/ REGULAR_FACE),
    //LOAD_RAW(/*seg*/ 0x13, _behaviorSegmentRomStart, _behaviorSegmentRomEnd),
    LOAD_RAW(/*seg*/ 0x07, 0x03F80000, 0x03F9B000),
    
    // Load "Super Mario 64" logo
    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, 0x140002d0),
    END_AREA(),
    AREA(/*index*/ 2, 0x1400035c),
    END_AREA(),
    FREE_LEVEL_POOL(),
    
    //SLEEP(/*frames*/ 2),
    BLACKOUT(/*active*/ FALSE),

    // Start animation
    LOAD_AREA(/*area*/ 1),

    CALL(/*arg*/ LVL_INTRO_PLAY_ITS_A_ME_MARIO, /*func*/ lvl_intro_update),
    SLEEP(/*frames*/ 30),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 16),
    CMD2A(/*unk2*/ 1),
    //CLEAR_LEVEL(),
    //SLEEP(/*frames*/ 2),
    //INIT_LEVEL(),
    //BLACKOUT(/*active*/ FALSE),
    
    //CALL(/*arg*/ _intro_segment_7SegmentRomStart, /*func*/ main_pool_free)
    //FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    //LOAD_RAW(/*seg*/ 0x13, _behaviorSegmentRomStart, _behaviorSegmentRomEnd),
    
    0x1A0C000A, 0x00B10650, 0x00B17909,
    
	LOAD_AREA(/*area*/ 2),
    SET_MENU_MUSIC(/*seq*/ SEQ_MENU_TITLE_SCREEN),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_STAR, /*time*/ 20, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 20),
    CALL_LOOP(/*arg*/ LVL_INTRO_REGULAR, /*func*/ lvl_intro_update),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ 100, 0x1400020c),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ 101, 0x14000238),
    JUMP(0x14000284),
};
