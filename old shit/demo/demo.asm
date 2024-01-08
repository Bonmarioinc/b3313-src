.include "trollfinity.asm" // Where every game function is

.headersize 0x14000000-0x269EA0

// reel level script
.org 0x14000200
.importobj "funy_scrpit.c.o"


.headersize 0x8018F240
.orga 0x3D0DC0+0x780

// funny text edit
.area 0x480
.importobj "print_intro_text_alt.c.o"
.endarea

.orga 0x358B0
J        print_intro_text
NOP
