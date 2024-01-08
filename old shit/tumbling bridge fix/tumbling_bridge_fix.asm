.include "trollfinity.asm" // Where every game function is

.headersize 0x80245000

.org 0x802ad76c
.area 0x88
.importobj "tumbling_bridge_act_2.c.o"
.endarea

.org 0x802ad828
.area 0x68
.importobj "tumbling_bridge_act_0.c.o"
.endarea
