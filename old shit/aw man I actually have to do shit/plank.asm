.include "trollfinity.asm" // Where every game function is

.headersize 0x0018F240
.orga 0x3D0DC0+0x8C00
.area 0x1800
.importobj "plank_geo.c.o"
.importobj "plank_model.c.o"
.endarea

.orga 0x16D08E8
.word wf_geo_000A58
.orga 0x1850B98
.word wf_geo_000A58
.orga 0x2C0D4B8
.word wf_geo_000A58
.orga 0x2E6C9E8
.word wf_geo_000A58
