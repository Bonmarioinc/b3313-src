
.headersize 0x8018F240
.orga 0x3D0DC0+0x2000

; I commented some unnecessary delay slot NOPs (the next instruction doesn't significantly corrupt state) to hopefully help performance lmao
fuckDisplayLists:
; push RA (not necessary)
;ADDIU   SP, SP, -0x18
;SW      RA, 0x0014 (SP)
; *currentDLCmd (pointer)
LUI     A0, 0x8042
; whether we're in a display list or not
ORI     A1, R0, 0x0000

_loopStart:
; grab current DL command
LW      T0, 0x0000 (A0)

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
	; currentDLArg ^= A3 (some RNG value?)
	LW      T3, 0x0004 (A0)
	ADDU    T3, T3, A3
	B       _loopCheck
	SW      T3, 0x0004 (A0)

_skipaf:
ADDIU   A0, A0, 0x0018
_loopCheckPlusResetState:
ADDIU   A1, R0, 0x0000
_loopCheck:
; *currentDLCmd += 8
ADDIU   A0, A0, 0x0008
; much faster skip
LW      T0, 0x0000 (A0)
BEQZ    T0, _skipaf
;NOP
; if currentDLCmd == 0 && currentDLArg == 0, break (probably cuts off tho so gotta find another way)
;BNEZ    T0, _noBreak
;NOP - seems like T0 is being corrupted, but on MIPS the branch is decided before the delay slot runs
;LW      T0, 0x0004 (A0)
;BEQZ    T0, _break
;NOP
_noBreak:
; if *currentDLCmd == 0x80560000, skip 0x10000 bytes because that's segment 1F
LUI     AT, 0x8056
BNE     A0, AT, _noskip
;NOP
SRL     T0, A0, 16
ADDIU   T0, T0, 1
SLL     A0, T0, 16
_noskip:
; if *currentDLCmd < 0x805E0000, continue
; (0x80560000 is the custom code part, and after that is irrelevant data)
LUI     AT, 0x805E
SLT     AT, A0, AT
BNEZ    AT, _loopStart
NOP
_break:
; pop RA (not necessary)
;LW      RA, 0x0014 (SP)
JR      RA
;ADDIU   SP, SP, 0x18
NOP
