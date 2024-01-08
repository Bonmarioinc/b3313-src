; load 7d7800-7e0000 to 807F7800
.org 0xfb9d4
load:
SW RA, 0x0010 (SP)
LUI T5, 0x8039
LW T6, 0xBE28 (T5)
addiu t7, t6, 0x0010
sw t7, 0xbe28 (T5)
LW A0, 0x0004 (T6)
LW A1, 0x0008 (T6)
JAL 0x802786F0
LW A2, 0x000C (T6)


lui a0, 0x807F
ori a0, a0, 0x7800
lui a1, 0x007D
ori a1, a1, 0x7800
lui a2, 0x007D
jal 0x80278504
ori a2, a2, 0xC800
lw ra, 0x0010 (SP)
jr ra
nop


; dust is spawn o, 0xFF, 0x007F8100
; Ad5E8 jal 7f8180

; BEHAVIOR 007D8130

; iterate all DLs starting at 80420000
	; start of DL is marked with E7 00 00 00 00 00 00 00
	; end of DL is marked with B8 00 00 00 00 00 00 00
; while active, add 0xF2 20 00 00 + o->oTimer&F * 0x10000 to pointer
; to deactivate, subtract the last added number (store somewhere in struct)

.org 0x7d7800
; function to fuck display lists
; replaced with better looking code lol
; push RA
ADDIU   SP, SP, -0x18
SW      RA, 0x0014 (SP)
; timer at 807FFFE0 for every 6 frames (because this function causes lag unlike the PCTTC one that checks every 7th frame)
LUI     AT, 0x8080
LBU     T0, 0xFFE0 (AT)
ADDIU   T0, T0, 0x0001
SLTI    T1, T0, 0x0006
BNEZ    T1, _break
SB      T0, 0xFFE0 (AT)
SB      R0, 0xFFE0 (AT)
; RNG check, 50% chance to break
JAL     0x80383BB0
NOP
ANDI    V0, V0, 0x0001
BEQZ    T1, _break
;NOP
; *currentDLCmd (pointer)
LUI     A0, 0x8042
; whether we're in a display list or not
ORI     A1, R0, 0x0000

; grab current DL command (later this is done at loopCheck)
LW      T0, 0x0000 (A0)
_loopStart:
; if inDisplayList != 1
ADDIU   AT, R0, 0x0001
BEQ     A1, AT, _else
;NOP
	; if currentDLCmd == 0xE7000000
	LUI     AT, 0xE700
	BNE     T0, AT, _loopCheck
	;NOP
	; && currentDLArg == 0x00000000
	LW      AT, 0x0004 (A0)
	BNEZ    AT, _loopCheck
	;NOP
	; state = 1
	ADDIU   A1, R0, 0x0001
	B       _loopCheck
	;NOP
_else:
	; if currentDLCmd == 0xB8000000, reset state, else proceed
	LUI     AT, 0xB800
	BEQ     T0, AT, _loopCheckPlusResetState
	;NOP
	; if (currentDLCmd & 0xFF000000) == 0xFD000000
	ORI     AT, R0, 0xFD
	SRL     T2, T0, 24
	BNE     AT, T2, _loopCheck
	;NOP
	; currentDLArg ^= RNG
	LW      T3, 0x0004 (A0)
	ADD     T3, T3, A3
	LUI     AT, 0x003F
	ORI     AT, AT, 0xFFFF
	AND     T3, T3, AT
	B       _loopCheck
	SW      T3, 0x0004 (A0)

_loopCheckPlusResetState:
ADDIU   A1, R0, 0x0000
_loopCheck:
; *currentDLCmd += 8
ADDIU   A0, A0, 0x0008
LW      T0, 0x0000 (A0) ; skip zeroes for faster scanning
BEQZ    T0, _loopCheck
NOP
; if currentDLCmd == 0 && currentDLArg == 0, break (probably cuts off tho so gotta find another way)
;BNEZ    T0, _noBreak
;NOP - seems like T0 is being corrupted, but on MIPS the outcome gets validated before the delay slot runs
;LW      T0, 0x0004 (A0)
;BEQZ    T0, _break
;NOP
_noBreak:
; if *currentDLCmd == 0x80560000, skip 0x10000 bytes because that's segment 1F
;LUI     AT, 0x8056
;BNE     A0, AT, _noskip
;;NOP
;SRL     T1, A0, 16
;ADDIU   T1, T1, 1
;SLL     A0, T1, 16
;LW      T0, 0x0000 (A0) ; pointer changed so load currentDLCmd again
;_noskip:
; if *currentDLCmd < 0x80560000, continue
; (0x80560000 is the custom code part, and after that is irrelevant data)
LUI     AT, 0x8056
SLT     AT, A0, AT
BNEZ    AT, _loopStart
NOP
_break:
; pop RA
LW      RA, 0x0014 (SP)
JR      RA
ADDIU   SP, SP, 0x18
;NOP


.org 0x7d8200
b:
addiu sp, sp, 0xffe8
sw ra, 0x14 (SP)
lui t0, 0x8036
lw t0, 0x1160(t0)
lw t2, 0x014c (t0)
beq t2, r0, reset
nop
action:
lw t2, 0x0154 (t0)
lui a0, 0x0001
addiu t3, r0, 0x0100
bne t2, t3, nosub
nop
lui a1, 0xFF00
sw r0, 0x0154 (t0)
nosub:
bne t2, r0, noadd
nop
lui a1, 0xF200
add a0, a1, a0
noadd:
jal 0x7f7800
or a3, a0, r0
lui t0, 0x8036
lw t0, 0x1160(t0)
lui at, 0xf220
lw t2, 0x0154 (t0)
addiu t2, t2, 0x1
sll t2, t2, 0x10
lui t3, 0xf200
or t2, t3, t2
sw t2, 0x00f0 (t0)

beq r0, r0, end
nop
reset:
lw t2, 0x0154 (t0)
bne t2, r0, end
nop
lui a0, 0x8034
jal 0x8027ae44
lbu a0, 0xb24a (a0)
;lw a0, 0x00f0 (t0)
;jal 0x7f7800
;sub a3, r0, a0
end:

lui t0, 0x8036
lw t0, 0x1160(t0)
lwc1 f2, 0x015c (t0)
lbu t3, 0x0189 (t0)
addiu t3, t3, 0x1
sll t3, t3, 0x8
mtc1 t3, f4
nop
nop
cvt.s.w f4, f4
nop
nop
nop
c.lt.s f2, f4
sw r0, 0x014c (t0)
bc1f normal
addiu at, r0, 0x1
sw at, 0x014c (t0)
normal:
lw ra, 0x14 (SP)
jr ra
addiu sp, sp, 0x0018
