;BigEye.asm

.definelabel RandU16, 0x80383BB0 ; noargs

.headersize 0x8018F240
.orga 0x3D0DC0+0xC00

@beh:
.word 0x00040000
.word 0x1101004b
.word 0x1c000000, 0x00000066, 0x1300008c
.word 0x2d000000
.word 0x08000000
.word 0x0c000000, @Big
.word 0x09000000

@Big:

addiu sp, sp, 0xffe0
sw ra, 0x001c(sp)
sw s0, 0x0018(sp)
sw s1, 0x0014(sp)

lui s0, 0x8036
lw s1, 0x1158(s0) ; mario
lw s0, 0x1160(s0) ; obj

addiu t0, r0, 0x0025
sh t0, 0x0002(s0) ; enable bilboarding

sw r0, 0x009c(s0)
lui t0, 0x43c8
sw t0, 0x01f8(s0)
sw t0, 0x01fc(s0)
lui t0, 0x0010
sw t0, 0x0130(s0)


lui t0, 0x4040
sw t0, 0x002c(s0)
sw t0, 0x0030(s0)
sw t0, 0x0034(s0) ; scale

lw t0, 0x014c(s0)
bne t0, r0, @@act1
nop

jal @dloop
nop

lwc1 f0, 0x00a0(s0)
lwc1 f2, 0x00a0(s1)

lhu t0, 0x018a(s0) ;distance from axis
mtc1 t0, f4

sub.s f0, f0, f2
abs.s f0, f0
cvt.s.w f4, f4

c.le.s f0, f4
nop
bc1f @@idle
addiu t0, r0, 0x0001
beq r0, r0, @@idle
sw t0, 0x014c(s0)
@@act1:

lw t0, 0x0154(s0)
slti t0, t0, 0x0200
beql t0, r0, @@idle ; disable if time
sw r0, 0x0074(s0)

lui t0, 0x4180
sw t0, 0x00b8(s0)

lw t0, 0x0134(s0)
beq t0, r0, @@idle
lui t0, 0x8034
sh r0, 0xb21e(t0)
@@idle:
@jidle:

lw t0, 0x0110(s0)
bne t0, r0, @@noblink
nop
jal RandU16
nop
addiu t0, r0, 0x007f
div v0, t0
mfhi t1
bne t1, r0, @@noblink
addiu t0, r0, 0x0001
sw t0, 0x0110(s0) ; set blink
@@noblink:
lw s1, 0x0014(sp)
lw s0, 0x0018(sp)
lw ra, 0x001c(sp)
jr ra
addiu sp, sp, 0x0020
nop
nop ; padding


@dloop:

lwc1 f0, 0x00a8(s0)
lwc1 f2, 0x00a8(s1)

lhu t0, 0x018a(s0) ;distance from axis
mtc1 t0, f4

sub.s f0, f0, f2
abs.s f0, f0
cvt.s.w f4, f4

c.le.s f0, f4
nop
bc1f @jidle
nop
jr ra
nop

