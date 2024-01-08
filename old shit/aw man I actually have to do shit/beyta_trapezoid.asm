.include "trollfinity.asm" // Where every game function is

.headersize 0x0018F240
.orga 0x10A09F0+0xEBD0
.importobj "beyta_trapezoid_model.c.o"
.orga 0x10A09F0+0xFB10
.importobj "beyta_trapezoid_collision.c.o"
