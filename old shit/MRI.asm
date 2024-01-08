; MRI.asm
; mister I

.definelabel SpawnObj, 0x8029EDCC ; a0 parent, a1 modelID, a2 beh
.definelabel PlaySound, 0x802CA190 ; a0 sound and properties
.definelabel CheckWall, 0x80251A48 ; a0 ptr pos, a1 wall top offset top, a2 max perp dist
.definelabel ObjSetHitbox, 0x802A34A4 ; a0 object, a1 hitbox
.definelabel RandU16, 0x80383BB0 ; noargs

.headersize 0x8018F240
.orga 0x3D0DC0

@beh:
.word 0x00040000
.word 0x1101204b
.word 0x2d000000
.word 0x1c000000, 0x00000066, 0x1300008c ; spawn pupil object
.word 0x21000000
.word 0x0c000000, 0x802a4120 ; leave this setup in just in case
.word 0x08000000
.word 0x0c000000, @Eye
.word 0x09000000

@beh_mario:
.word 0x00040000
.word 0x1101204b
.word 0x2d000000
.word 0x1c000000, 0x000000FE, 0x1300008c ; spawn pupil object
.word 0x21000000
.word 0x0c000000, 0x802a4120 ; leave this setup in just in case
.word 0x08000000
.word 0x0c000000, @Eye
.word 0x09000000

@shootbeh:
.word 0x00040000
.word 0x1101204b
.word 0x08000000
.word 0x0c000000, @shootm
.word 0x09000000

@jmpt:
.word @Action0, @Action1, @Action2, @Shooty ; jump table


@Eye:
addiu sp, sp, 0xffe0
sw ra, 0x001c(sp)
sw s0, 0x0018(sp)
sw s1, 0x0014(sp)

lui s0, 0x8036
lw s1, 0x1158(s0) ; mario
jal @Shooty
lw s0, 0x1160(s0) ; obj

lw t0, 0x0134(s0)
beq t0, r0, @@nodedd
lui t0, 0x8034
sh r0, 0xb21e(t0)
addiu t0, r0, 0x0001
sw t0, 0x014c(s0)
sw r0, 0x00b8(s0)
@@nodedd:

lw t0, 0x014c(s0)
li t1,@jmpt
sll t0, t0, 0x02
addu t0, t0, t1
lw t0, 0x0000(t0) ;
JALR t0
nop
lw t0, 0x0110(s0)
bne t0, r0, @@idle
nop
jal RandU16
nop
addiu t0, r0, 0x007F
div v0, t0
mfhi t1
bne t1, r0, @@idle
addiu t0, r0, 0x0001
sw t0, 0x0110(s0) ; set blink
@@idle:

lw s1, 0x0014(sp)
lw s0, 0x0018(sp)
lw ra, 0x001c(sp)
jr ra
addiu sp, sp, 0x0020

; One action for the searching "back and forth" motions
; One action for tracking mario when he's in line of sight
; One action for rushing at mario
; One Action to reset him

@Action0:
addiu sp, sp, 0xffe0
sw ra, 0x001c(sp)
sw r0, 0x00b8(s0)
; check if mario is in range
lui t0, 0x451c
mtc1 t0, f2
lwc1 f0, 0x015c(s0)
c.le.s f0, f2
addu t0, r0, r0 ; speed
bc1fl @@nodist
sh t0, 0x00f6(s0)

;f4 speed accum
;f6 target rotation
;fa speed
;fc dir flag

lh t1, 0x00fc(s0)
bne t1, r0, @@dir
addiu t1, r0, 0xc000 ; ANGLES TO SEARCH BETWEEN
addiu t1, r0, 0x4000 ; ANGLES TO SEARCH BETWEEN
@@dir:
sh t1, 0x00f6(s0)


@@nodist:

lhu t0, 0x00ca(s0) ; get current rot
lhu t1, 0x00f6(s0) ; get tar rot
subu t1, t0, t1
sra t2, t1, 0x1f
addu t1, t1, t2
xor t1, t1, t2 ; get abs value
srl t2, t1, 0x03
addiu t3, t2, 0x0040 ; 0x80 + abs(dif/32)
sh t3, 0x00fa(s0) ; accel

; switch direction flag if within 0x100 angles of target
slt t2, t1, 0x0400 ; 
beq t2, r0, @@switch
lh t0, 0x00fc(s0)
xori t0, t0, 0x0001
sh t0, 0x00fc(s0)
addiu t0, r0, 0x0001
sw t0, 0x014c(s0)
addiu t0, r0, 0x0004
sw t0, 0x009c(s0) ; lazy
@@switch:

lh t0, 0x00fa(s0) ; accel
lh t1, 0x00fc(s0)
lh t2, 0x00ca(s0)
bne t1, r0, @@dir2
addu t3, t2, t0
subu t3, t2, t0
@@dir2:
sh t3, 0x00ca(s0)
lw ra, 0x001c(sp)
jr ra
addiu sp, sp, 0x0020

;
@Action1:
addiu sp, sp, 0xffe0
lh t0, 0x00f6(s0)
bne t0, r0, @@notz
sw ra, 0x001c(sp)
sw r0, 0x00c8(s0)

lui t0, 0x451c
mtc1 t0, f2
lwc1 f0, 0x015c(s0)
c.le.s f0, f2
addu t0, r0, r0
bc1f @@idle
nop
beq r0, r0, @@idle
sw r0, 0x014c(s0)
@@notz:
lw t0, 0x0154(s0)
slti t0, t0, 0x0030
bne t0, r0, @@nodone
lw t0, 0x0150(s0) ; subaction
sw r0, 0x009c(s0)
sh r0, 0x00f8(s0)
sw r0, 0x014c(s0)
beq r0, r0, @@idle
@@nodone:
lh t1, 0x00f8(s0) ; subaction dir flag
bne t0, r0, @@wait
lw t2, 0x009c(s0) ; gonna use this as a count down timer
bne t2, r0, @@movegd
lh t0, 0x00f8(s0)
addiu t0, r0, 0x0010
sw t0, 0x009c(s0)
addiu t0, r0, 0x0001
sw t0, 0x0150(s0)
lh t0, 0x00f8(s0)
xori t0, t0, 0x0001
sh t0, 0x00f8(s0)
@@movegd:
lh t2, 0x00ca(s0)
addiu t1, r0, 0x0800
beq t0, r0, @@sums
addu t3, t2, t1
subu t3, t2, t1
@@sums:
beq r0, r0, @@idle
sh t3, 0x00ca(s0)

@@wait:
bne t2, r0, @@idle
addiu t0, r0, 0x0004
lh t1, 0x00f8(s0)
sllv t1, t0, t1
sw t1, 0x009c(s0)
sw r0, 0x0150(s0)


@@idle:
lw ra, 0x001c(sp)
jr ra
addiu sp, sp, 0x0020

;
@Action2:
addiu sp, sp, 0xffe0
sw ra, 0x001c(sp)

addiu t0, r0, 0x0001
sw t0, 0x0114(s0)

lw t0, 0x0160(s0)
sw t0, 0x00c8(s0) ; copy angle to mario to angle

lh t0, 0x0100(s0) ; get counter for sight objects
slt t1, t0, 0x0002
bne t1, r0, @@nosee


lui t0, 0x4280
sw t0, 0x00b8(s0) ; set spd
lui t0, 0x42a0
sw t0, 0x01f8(s0)
sw t0, 0x01fc(s0)
sw r0, 0x009c(s0)
ori t0, r0, 0x0010
sw t0, 0x0130(s0)
lui a0, 0x4004
jal PlaySound
ori a0, a0, 0xFF01



beq r0, r0, @@notime
@@nosee:

lh t0, 0x0102(s0)
slti t1, t0, 0x0003
bne t1, r0, @@nowall
addiu t0, r0, 0x0001
sw r0, 0x0100(s0)
beq r0, r0, @@notime
sw t0, 0x014c(s0)


@@nowall:

lw t0, 0x0154(s0)
addiu t1, r0, 0x000f
div t0, t1
mfhi t0
bne t0, r0, @@notime

or a0, r0, s0
li a2,@shootbeh-0x80000000
jal SpawnObj
or a1, r0, r0
lw t0, 0x00c8(s0)
sw t0, 0x00c8(v0)
sw v0, 0x0104(s0)





@@notime:
lw ra, 0x001c(sp)
jr ra
addiu sp, sp, 0x0020

;
@Shooty: ; handles the "vision" of the eye

addiu sp, sp, 0xffe0
lui t0, 0x451c
mtc1 t0, f2
lwc1 f0, 0x015c(s0)
c.le.s f0, f2
sw ra, 0x001c(sp)
bc1f @@noseeu2
lw t0, 0x0134(s0)
bne t0, r0, @@noseeu2
lw t0, 0x014c(s0)
addiu t1, r0, 0x0002
beq t0, t1, @@noseeu2
lhu t0, 0x0162(s0)
lhu t1, 0x00ca(s0)
subu t0, t1, t0
sra t1, t0, 0x1f
addu t0, t0, t1
xor t1, t0, t1
sw t1, 0x0108(s0)
slti t0, t1, 0x2800
beq t0, r0, @@noseeu
sw r0, 0x0114(s0)

addiu t0, r0, 0x0001
sw t0, 0x0114(s0)

lw t0, 0x0154(s0)
andi t0, t0, 0x0001
bne t0, r0, @@noseeu
or a0, r0, s0
li a2,@shootbeh-0x80000000
jal SpawnObj
or a1, r0, r0
lw t0, 0x0160(s0)
sw t0, 0x00c8(v0)
sw v0, 0x0104(s0)
addiu t0, r0, 0x0001
sw t0, 0x0100(v0)




@@noseeu:

lh t0, 0x0100(s0)
beq t0, r0, @@noseeu2
addiu t0, r0, 0x0002
sw t0, 0x014c(s0)
sw r0, 0x0100(s0)
@@noseeu2:
lw ra, 0x001c(sp)
jr ra
addiu sp, sp, 0x0020



@shootm:
addiu sp, sp, 0xffe0
sw ra, 0x001c(sp)
sw s0, 0x0018(sp)

lui a0, 0x8036
lw t1, 0x1158(a0) ; mario
lw a0, 0x1160(a0) ; obj
lw s0, 0x0068(a0) ; get parent
lw t3, 0x014c(s0)
lw t0, 0x0114(s0)
sb t0, 0x0074(a0)
sb t0, 0x0075(a0)
addiu t2, r0, 0x0002
bne t2, t3, @@nodis
@@nodiss:
lw t0, 0x0100(a0)
beq t0, r0, @@nodis
nop
beq r0, r0, @@nomario
sw r0, 0x0074(a0)
@@nodis:
ori t0, r0, 0x0010
sw t0, 0x0130(a0)
lui t0, 0x4248
sw t0, 0x00b8(a0) ; set spd
LW t0, 0x0160(a0)
sw t0, 0x00c8(a0)
lw t2, 0x00a4(t1)
sw t2, 0x00a4(a0)
sw r0, 0x009c(a0)
lui a2, 0x4248 ; 30
sw a2, 0x01fc(a0)
sw a2, 0x01f8(a0)
addiu a0, a0, 0x00a0
jal CheckWall
or a1, r0, r0 ; 0
beq v0, r0, @@nowall
lui t0, 0x8036
lw t0, 0x1160(t0)
lh t1, 0x0102(s0)
addiu t1, t1, 0x0001
sh t1, 0x0102(s0) ; out of sight flag
sw r0, 0x0074(t0)
sh r0, 0x0100(s0) ; counter
beq r0, r0, @@nomario
@@nowall:
lui t0, 0x8036
lw t0, 0x1160(t0)
lw t1, 0x0134(t0)
beq t1, r0, @@nomario
lh t1, 0x0100(s0)
addiu t1, t1, 0x0001
sh t1, 0x0100(s0) ; out of sight flag
sw r0, 0x0074(t0)
sh r0, 0x0102(s0) ; counter
@@nomario:
lw s0, 0x0018(sp)
lw ra, 0x001c(sp)
jr ra
addiu sp, sp, 0x0020
