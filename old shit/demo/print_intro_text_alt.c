#include <ultra64.h>
#include <PR/ultratypes.h>

#include "prevent_bss_reordering.h"
#include "sm64.h"
#include "game_init.h"
#include "main.h"
#include "engine/math_util.h"
#include "area.h"
#include "level_update.h"
#include "save_file.h"
#include "sound_init.h"
#include "level_table.h"
#include "course_table.h"
#include "rumble_init.h"
#include "gfx_dimensions.h"
#include "behavior_data.h"
#include "object_list_processor.h"
#include "engine/surface_load.h"
#include "ingame_menu.h"
#include "screen_transition.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "print.h"
#include "hud.h"
#include "audio/external.h"
#include "rendering_graph_node.h"
#include "engine/geo_layout.h"
#include "dialog_ids.h"
#include "game/area.h"
#include "game/game_init.h"
#include "game/level_update.h"
#include "game/main.h"
#include "game/memory.h"
#include "game/print.h"
#include "game/save_file.h"
#include "game/sound_init.h"
#include "game/rumble_init.h"
#include "seq_ids.h"



s32 save_good(void);
s32 has_save_data(void);

void print_intro_text(void) {
    if ((gGlobalTimer & 31) < 20) {
        if (gControllerBits == 0) {
            print_text_centered(SCREEN_WIDTH / 2, 20, "YAHA");
        } else {
			if (save_good()) {
				print_text_centered(60, 50, "PRESS");
				print_text_centered(60, 32, "START");
			}
			else {
				print_text_centered(60, 50, "BAD");
				print_text_centered(60, 32, "FILE");
			}
			
			if (has_save_data()) {
				print_text(SCREEN_WIDTH - 40, 50, "L");
				print_text(SCREEN_WIDTH - 160, 32, "DELETE FILE");
			}
        }
    }
    
    if (!save_good()) {
		// fuck you, you can't press start
		gPlayer1Controller->buttonPressed &= ~START_BUTTON;
		// problem? :troll:
	}
    
	// yaha with L button
	if (gPlayer1Controller->buttonPressed & L_TRIG) {
		play_sound(0x242E8081, gGlobalSoundSource);
		// delet save if exists 
		if (has_save_data()) {
			save_file_erase(0);
		}
	}
}

u8 full_save[] = { 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

s32 save_good(void) {
	int i;
	
	if (!has_save_data()) {
		return TRUE;
	}
	
	// make sure save only has the stars you can get ingame
	for (i = 0; i <= 0x18; i++) {
		u8 flags = save_file_get_star_flags(0, i);
		if ((flags | full_save[i]) != full_save[i]) { // we have extra stars!!
			return FALSE;
		}
	}
	
	return TRUE;
}

s32 has_save_data(void) {
	return save_file_exists(0);
}
