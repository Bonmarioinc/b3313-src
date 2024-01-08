.n64
.open "b3313 silved.z64", "b3313 new.z64", 0

.include "trollfinity.asm" // Where every game function is

// scuttlebug
// segment 0x0D
.headersize 0x0D000000-0x1F1B30
.orga 0x1F1B30+0x390 // 0x394 but it gets padded tro
.importobj "actors/scuttlebug/geo.inc.c.o"
// segment 0x06
.headersize 0x06000000-0xA647F0
.orga 0xA647F0+0x100E0
.importobj "actors/scuttlebug/model.inc.c.o"
// anim shit
// bhv
//.orga bhvStart+0x2B5C+0x0C
//.word scuttlebug_seg6_anims_06015064

.close
