.definelabel memcpy, 0x803273f0
.definelabel _Printf, 0x80326260
.definelabel sprintf, 0x803224f0
.definelabel __ll_mul, 0x80324258
.definelabel __ull_div, 0x80324158
.definelabel bzero, 0x80324570
.definelabel sqrtf, 0x80323a50

.definelabel osClockRate, 0x80335910
.definelabel osSetTime, 0x803223b0
.definelabel osGetTime, 0x80325070
.definelabel osWritebackDCacheAll, 0x80322f40
.definelabel osViBlack, 0x80323340
.definelabel osViSwapBuffer, 0x80323a00
.definelabel osSetEventMesg, 0x803225d0
.definelabel osRecvMesg, 0x80322800
.definelabel osCreateMesgQueue, 0x803225a0
.definelabel osCreateThread, 0x803226b0
.definelabel osStartThread, 0x80322df0
.definelabel osContStartReadData, 0x80323a60
.definelabel osContGetReadData, 0x80323b24

.definelabel gFramebuffers, 0x8038f800
.definelabel sRenderedFramebuffer, 0x8032d5d8

.definelabel gPlayer1Controller, 0x8032d5e4
.definelabel gControllers, 0x8033af90
.definelabel gControllerPads, 0x8033aff8
.definelabel gControllerBits, 0x8033b078
.definelabel adjust_analog_stick, 0x80248304

.definelabel gSIEventMesgQueue, 0x8033af78

.definelabel D_8033489C, 0x803359ac


.definelabel sMarioCamState, 0x8032df60
.definelabel gCameraZoomDist, 0x8032df4c
.definelabel sZoomAmount, 0x8033c764
.definelabel sCSideButtonYaw, 0x8033c768
.definelabel sYawSpeed, 0x8032df34
.definelabel sStatusFlags, 0x8033c84a
.definelabel sCameraYawAfterDoorCutscene, 0x8033c620
.definelabel sAvoidYawVel, 0x8033c61e
.definelabel sMarioGeometry, 0x8033c5e8
.definelabel gCurrLevelArea, 0x8032df38

.definelabel gLakituState, 0x8033c698
.definelabel find_ceil, 0x80381264
.definelabel find_floor, 0x80381900
.definelabel find_water_level, 0x80381ba0
.definelabel find_poison_gas_level, 0x80381d3c
.definelabel handle_c_button_movement, 0x8028bd98
.definelabel vec3f_get_dist_and_angle, 0x8037a69c
.definelabel vec3f_set_dist_and_angle, 0x8037a788
.definelabel gCameraMovementFlags, 0x8033c848
.definelabel set_cam_angle, 0x80288718
.definelabel set_handheld_shake, 0x80288888
.definelabel vec3f_copy, 0x80378800
.definelabel set_or_approach_f32_asymptotic, 0x8028935c                
.definelabel approach_f32_asymptotic_bool, 0x802893f4                
.definelabel approach_f32_asymptotic, 0x80289488                
.definelabel approach_s16_asymptotic_bool, 0x802894b4                
.definelabel approach_s16_asymptotic, 0x8028956c                
.definelabel approach_vec3f_asymptotic, 0x80289610                
.definelabel set_or_approach_vec3f_asymptotic, 0x80289684                
.definelabel approach_vec3s_asymptotic, 0x802896f8                
.definelabel camera_approach_s16_symmetric_bool, 0x8028976c                
.definelabel camera_approach_s16_symmetric, 0x8028984c                
.definelabel set_or_approach_s16_symmetric, 0x8028993c                
.definelabel camera_approach_f32_symmetric_bool, 0x802899cc                
.definelabel camera_approach_f32_symmetric, 0x80289b0c
.definelabel calc_hor_dist, 0x8028accc
.definelabel gSineTable, 0x80386000
.definelabel gCosineTable, 0x80387000
.definelabel calc_y_to_curr_floor, 0x8027fc18
.definelabel gMarioStates, 0x8033b170
.definelabel approach_camera_height, 0x8028c8f0
.definelabel is_range_behind_surface, 0x8028a6bc
.definelabel clamp_positions_and_find_yaw, 0x80289f88
.definelabel gCurrLevelNum, 0x8032ddf8
.definelabel sSelectionFlags, 0x8033c684
.definelabel scale_along_line, 0x8028a834
.definelabel get_dialog_id, 0x802d8c6c
.definelabel collide_with_walls, 0x80288f5c
.definelabel find_wall_collisions, 0x80380e8c
.definelabel atan2s, 0x8037a9a8             
.definelabel calc_avoid_yaw, 0x8028a080
.definelabel is_surf_within_bounding_box, 0x8028a0f4 
.definelabel is_mario_behind_surface, 0x8028a7ec  

.definelabel sSurfacePool, 0x8038ee9c
.definelabel sSurfacePoolSize, 0x8038eea0
.definelabel gSurfacesAllocated, 0x80361170
.definelabel alloc_surface, 0x803824F8

.definelabel gCurrentObject, 0x80361160
.definelabel gMarioObject, 0x80361158
.definelabel gCheckingSurfaceCollisionsForCamera, 0x80361180
.definelabel gMarioState, 0x8032d93c

.definelabel vec3s_copy, 0x8037893c

.definelabel bhv_moving_blue_coin_init, 0x802e6098
.definelabel bhv_moving_yellow_coin_loop, 0x802e5f64
.definelabel common_anchor_mario_behavior, 0x802a958c
.definelabel cur_obj_init_animation_with_sound, 0x8029f4b4
.definelabel cur_obj_check_if_near_animation_end, 0x8029ff04                
.definelabel cur_obj_check_anim_frame, 0x802a0008                
.definelabel cur_obj_play_sound_2, 0x802ca1e0                
.definelabel set_object_visibility, 0x802e5360                
.definelabel geo_update_held_mario_pos, 0x802a719c                
.definelabel cur_obj_scale, 0x8029f430                
.definelabel cur_obj_become_intangible, 0x802a05b4                
.definelabel cur_obj_disable_rendering, 0x8029f66c                
.definelabel cur_obj_rotate_yaw_toward, 0x8029e5ec                
.definelabel cur_obj_extend_animation_if_at_end, 0x8029fea4                
.definelabel obj_lava_death, 0x802e5b18                
.definelabel spawn_object, 0x8029edcc                
.definelabel random_float, 0x80383cb4                
.definelabel cur_obj_update_floor_and_walls, 0x802a2320                
.definelabel sObjFloor, 0x80361450
.definelabel cur_obj_move_standard, 0x802a2348
.definelabel cur_obj_get_thrown_or_placed, 0x802a0380   
.definelabel obj_angle_to_object, 0x8029e694                
.definelabel cur_obj_angle_to_home, 0x802a2748                
.definelabel cur_obj_set_model, 0x802a04c0                
.definelabel obj_set_hitbox, 0x802a34a4                
.definelabel cur_obj_call_action_function, 0x802a3e30                
.definelabel obj_copy_pos, 0x8029f120                
.definelabel cur_obj_get_dropped, 0x802a0474                
.definelabel cur_obj_become_tangible, 0x802a05d4                
.definelabel cur_obj_enable_rendering_and_become_tangible, 0x8029f600                

.definelabel geo_switch_anim_state, 0x8029db48                
.definelabel geo_switch_tuxie_mother_eyes, 0x802bfbac                
.definelabel gCurGraphNodeCamera, 0x8032defc                
.definelabel gCurGraphNodeObject, 0x8032df00
.definelabel create_transformation_from_matrices, 0x8029de80                
.definelabel obj_update_pos_from_parent_transformation, 0x8029dcd4
.definelabel obj_set_gfx_pos_from_pos, 0x8029f188                
.definelabel geo_update_projectile_pos_from_parent, 0x8029d890                
.definelabel geo_update_body_rot_from_parent, 0x802b798c                

.definelabel mario_cap_seg3_dl_03022f48, 0x03022f48

.definelabel sDelayInvincTimer, 0x8033b270                
.definelabel sInvulnerable, 0x8033b272                    
.definelabel sInteractionHandlers, 0x8032d950
.definelabel sDisplayingDoorText, 0x8032da90
.definelabel sJustTeleported, 0x8032da94
.definelabel check_kick_or_punch_wall, 0x80250230                

.definelabel cur_obj_unhide, 0x8029f694                
.definelabel cur_obj_hide, 0x8029f6bc                
