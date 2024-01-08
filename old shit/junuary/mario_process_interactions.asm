.include "trollfinity.asm" // Where every game function is

.headersize 0x80245000
.org 0x802503F0
.area 0x802505C4-0x802503F0 
.importobj "mario_process_interactions.c.o"
.endarea
