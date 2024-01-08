.include "trollfinity.asm" // Where every game function is

.definelabel bhvStart, 0x31b3160
//.definelabel bhvStart, 0x31B3110

// amp
// segment 0x0F
.headersize 0x0F000000-0x2008D0
.orga 0x2008D0+0x20 // 0x28 but it gets padded tro
.importobj "actors/amp/geo.inc.c.o"
// segment 0x08
.headersize 0x08000000-0xA81860
.orga 0xA81860+0x1318
.importobj "actors/amp/model.inc.c.o"

// bully
// segment 0x0C
.headersize 0x0C000000-0x134A70
.orga 0x134A70+0x0
.importobj "actors/bully/geo.inc.c.o"
// segment 0x05
.headersize 0x05000000-0x87E250
.orga 0x87E250+0x0
.importobj "actors/bully/model.inc.c.o"

// chain chomp
// segment 0x0D
.headersize 0x0D000000-0x1D7C90
.orga 0x1D7C90+0x5E0 // 0x5EC but it gets padded tro
.importobj "actors/chain_chomp/geo.inc.c.o"
// segment 0x06
.headersize 0x06000000-0xA09960
.orga 0xA09960+0x233D0
.importobj "actors/chain_chomp/model.inc.c.o"

// chuckya
// segment 0x0F
.headersize 0x0F000000-0x2008D0
.orga 0x2008D0+0x1D0 // 0x1D8 but it gets padded tro
.importobj "actors/chuckya/geo.inc.c.o"
// segment 0x08
.headersize 0x08000000-0xA81860
.orga 0xA81860+0x66D0
.importobj "actors/chuckya/model.inc.c.o"

// heavy hoe
// segment 0x0C
.headersize 0x0C000000-0x132850
.orga 0x132850+0x280 // 0x28C but it gets padded tro
.importobj "actors/heave_ho/geo.inc.c.o"
// segment 0x05
.headersize 0x05000000-0x860EF0
.orga 0x860EF0+0xE9C0
.importobj "actors/heave_ho/model.inc.c.o"
// not segment 0x05
.headersize 0x80720000-0x860EF0
.importobj "actors/heave_ho/trollfunc.c.o"
// anim shit
// bhv
.orga bhvStart+0x1548+0x0C
.word heave_ho_seg5_anims_0501534C
// asm fix (rewinding anim doesn't exist, just use default anim)
.orga 0x6CE10
ADDIU A0, R0, 0x0000

// king bom
// segment 0x0C
.headersize 0x0C000000-0x13B5D0
.orga 0x13B5D0+0x0
.importobj "actors/king_bobomb/geo.inc.c.o"
// segment 0x05
.headersize 0x05000000-0x88C3D0
.orga 0x88C3D0+0x0
.importobj "actors/king_bobomb/model.inc.c.o"
// TODO: port the behavior code so the anims don't crash the game lol
// anim shit
// bhv
//.orga 0x3177000
//.word king_bobomb_seg5_anims_0500FE30

// kopa
// segment 0x0D
.headersize 0x0D000000-0x1D7C90
.orga 0x1D7C90+0xD0
.importobj "actors/koopa/geo.inc.c.o"
// segment 0x06
.headersize 0x06000000-0xA09960
.orga 0xA09960+0x25A0
.importobj "actors/koopa/model.inc.c.o"

// Million Instructions Per Second
// segment 0x0D
//.headersize 0x0D000000-0x1E4BF0
//.orga 0x1E4BF0+0x440 // 0x448 but it gets padded tro
//.importobj "actors/mips/geo.inc.c.o"
// segment 0x06
//.headersize 0x06000000-0xA36AF0
//.orga 0xA36AF0+0xFB80
//.importobj "actors/mips/model.inc.c.o"

// ping
// segment 0x0C
.headersize 0x0C000000-0x1656E0
.orga 0x1656E0+0x100 // 0x104 but it gets padded tro
.importobj "actors/penguin/geo.inc.c.o"
// segment 0x05
.headersize 0x05000000-0x8FB8B0
.orga 0x8FB8B0+0x2D80
.importobj "actors/penguin/model.inc.c.o"

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
.orga bhvStart+0x2B5C+0x0C
.word scuttlebug_seg6_anims_06015064

// snowman
// segment 0x0C
.headersize 0x0C000000-0x1656E0
.orga 0x1656E0+0x210 // 0x21C but it gets padded tro
.importobj "actors/snowman/geo.inc.c.o"
// segment 0x05
.headersize 0x05000000-0x8FB8B0
.orga 0x8FB8B0+0x8C10
.importobj "actors/snowman/model.inc.c.o"

// sushi & unagi
// eat the entire space that sushi, unagi and whirlpool have combined
// unagi is moved to segment 1F, and we don't give a fuck about whirlpool
// segment 0x0C
.headersize 0x0C000000-0x145C10
.orga 0x145C10+0x60 // 0x68 but it gets padded tro
.importobj "actors/sushi/geo.inc.c.o"
// segment 0x05
.headersize 0x05000000-0x8A5470
.orga 0x8A5470+0x8ED0
.area 0x13D28-0x8ED0
.importobj "actors/sushi/model.inc.c.o"
.importobj "actors/unagi/model.inc.c.o"
.importobj "actors/unagi/anims1.c.o"
.endarea
// anim shit
// bhv
.orga bhvStart+0x2338+0x0C
.word sushi_seg5_anims_0500AE54

// unagi
// segment 0x0C
.headersize 0x0C000000-0x145C10
.orga 0x145C10+0x100 // 0x10C but it gets padded tro
.importobj "actors/unagi/geo.inc.c.o"
// model imported above
// anim separately in segment 1F
.headersize 0x0018F240
.orga 0x3D0DC0+0xDA00
.area 0x1E00
.importobj "actors/unagi/anims2.c.o"
.endarea
// anim patch bhv
.orga bhvStart+0x4f40+0x0C
.word unagi_seg5_anims_05012824

// wigger
// body
// segment 0x05
.headersize 0x05000000-0x960230
.orga 0x960230+0xC770 // 0xC778 but it gets padded tro
.importobj "actors/wiggler_body/geo.inc.c.o"
// segment 0x05
.headersize 0x05000000-0x960230
.orga 0x960230+0x5A30
.area 0xC770-0x5A30
.importobj "actors/wiggler_body/model.inc.c.o"
.endarea
// anim shit
// bhv
.orga bhvStart+0x48e0+0x0C
.word wiggler_seg5_anims_0500C874
// head
// segment 0x0C
.headersize 0x0C000000-0x187FA0
.orga 0x187FA0+0x30
.importobj "actors/wiggler_head/geo.inc.c.o"
// segment 0x05
.headersize 0x05000000-0x960230
.orga 0x960230+0xC878
.area 0xEC8C-0xC878
.importobj "actors/wiggler_head/model.inc.c.o"
.endarea
// anim shit
// bhv
.orga bhvStart+0x4898+0x10
.word wiggler_seg5_anims_0500EC8C
