.include "trollfinity.asm" // Where every game function is

// bhv script
.headersize 0x0018F240
.orga 0x3D0DC0+0x3000
.importobj "bhvscripts.o"

// actual bhv
.headersize 0x8018F240
.importobj "bhv.o"

// model
.headersize 0x0018F240
.importobj "models.o"

// load the model globally
.orga 0x2ABE34
.word RCP_HmsEnemyhopper
