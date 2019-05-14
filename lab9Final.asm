%include "io64.inc"


section .data

	common	y 8	; define a global variabl
	common	z 8	; define a global variabl
	common	A 800	; define a global variabl
	common	t 8	; define a global variabl
	common	x4 800	; define a global variabl

	_L11:	db "inside f", 0  ;define a global string
	_L12:	db "enter X", 0  ;define a global string
	_L13:	db "enter X", 0  ;define a global string
	_L14:	db " x is ", 0  ;define a global string

section .text
	global main

f:
	mov	r8, rsp		;FUNC header RSP has to be at most RBP
	add	r8, -24		;adjust Stack Pointer for Activation record
	mov	[r8], rbp	;FUNC header stored old BP
	mov	[r8+8], rsp	;FUNC header store old BP
	mov	rsp, r8		;FUNC header new SP

	PRINT_STRING _L11		;printing a string
	NEWLINE

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 16		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	PRINT_DEC  8, RAX	;Printing a number.
	NEWLINE

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 16		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]

	mov	rbp,[rsp]	;FUNC end restore old BP
	mov	rsp,[rsp+8]	;FUNC end restore old SP
	RET

	mov	rbp,[rsp]	;FUNC end restore old BP
	mov	rsp,[rsp+8]	;FUNC end restore old SP
	xor	rax, rax		; no value specificed, then it is 0
	ret
main:
	mov	rbp, rsp		;SPECIAL RSP to RSB for MAIN only
	mov	r8, rsp		;FUNC header RSP has to be at most RBP
	add	r8, -144		;adjust Stack Pointer for Activation record
	mov	[r8], rbp	;FUNC header stored old BP
	mov	[r8+8], rsp	;FUNC header store old BP
	mov	rsp, r8		;FUNC header new SP

	MOV	RAX, 2		;Moving RHS to RAX
	MOV	[RSP + 24], RAX	;Saving RAX in memory


	MOV	RBX, RSP
	SUB	RBX, 32		;RBX is the new target for the function call
	MOV	RAX, [RSP + 24]	;Copy actual to RAX
	MOV	[RBX + 16], RAX	;Copy RAX to RBX target
	CALL	f

	MOV	RCX, RAX

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 16		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	[RAX], RCX	;Assigning LHS to RHS

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 16		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	PRINT_DEC  8, RAX	;Printing a number.
	NEWLINE

	MOV	RAX, 0		;Moving RHS to RAX
	MOV	RCX, RAX

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	[RAX], RCX	;Assigning LHS to RHS

_L15:	;Begin while loop

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	MOV	[RSP + 96], RAX	;Saving RAX in memory
	MOV	RAX, 5		;Moving RHS to RAX
	MOV	RBX, RAX		;Moving RAX obtained from LHS to RBX.
	MOV	RAX, [RSP + 96]	;Moving RHS into RAX
	CMP	RAX, RBX
	SETL	AL
	MOV	RBX, 1
	AND	RAX, RBX

	CMP	RAX, 0
	JE	_L16

	PRINT_STRING _L12		;printing a string
	NEWLINE

	MOV	RAX, 0		;Clearing RAX
	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	SHL	RAX, 3		;Multiplying offset by WSIZE
	ADD	RAX, 40		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	GET_DEC 8, [RAX]		;Reading in a variable.

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	MOV	[RSP + 104], RAX	;Saving RAX in memory
	MOV	RAX, 1		;Moving RHS to RAX
	MOV	RBX, RAX		;Moving RAX obtained from LHS to RBX.
	MOV	RAX, [RSP + 104]	;Moving RHS into RAX
	ADD	RAX, RBX
	MOV	RCX, RAX

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	[RAX], RCX	;Assigning LHS to RHS


	JMP	_L15
_L16:
	;End while loop.

	MOV	RAX, 0		;Moving RHS to RAX
	MOV	RCX, RAX

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	[RAX], RCX	;Assigning LHS to RHS

_L17:	;Begin while loop

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	MOV	[RSP + 112], RAX	;Saving RAX in memory
	MOV	RAX, 5		;Moving RHS to RAX
	MOV	RBX, RAX		;Moving RAX obtained from LHS to RBX.
	MOV	RAX, [RSP + 112]	;Moving RHS into RAX
	CMP	RAX, RBX
	SETL	AL
	MOV	RBX, 1
	AND	RAX, RBX

	CMP	RAX, 0
	JE	_L18

	MOV	RAX, 0		;Clearing RAX
	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	SHL	RAX, 3		;Multiplying offset by WSIZE
	ADD	RAX, 40		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	MOV	[RSP + 120], RAX	;Saving RAX in memory
	MOV	RAX, 0		;Clearing RAX
	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	SHL	RAX, 3		;Multiplying offset by WSIZE
	ADD	RAX, 40		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	MOV	RBX, RAX		;Moving RAX obtained from LHS to RBX.
	MOV	RAX, [RSP + 120]	;Moving RHS into RAX
	IMUL	RBX
	PRINT_DEC  8, RAX	;Printing a number.
	NEWLINE

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	RAX, [RAX]
	MOV	[RSP + 128], RAX	;Saving RAX in memory
	MOV	RAX, 1		;Moving RHS to RAX
	MOV	RBX, RAX		;Moving RAX obtained from LHS to RBX.
	MOV	RAX, [RSP + 128]	;Moving RHS into RAX
	ADD	RAX, RBX
	MOV	RCX, RAX

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, 80		;Getting ident offset
	ADD	RAX, RSP		;Identifier offset + stack pointer

	MOV	[RAX], RCX	;Assigning LHS to RHS


	JMP	_L17
_L18:
	;End while loop.

	PRINT_STRING _L13		;printing a string
	NEWLINE

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, t		;Moving variable into RAX

	GET_DEC 8, [RAX]		;Reading in a variable.

	PRINT_STRING _L14		;printing a string
	NEWLINE

	MOV	RAX, 0		;Clearing RAX
	ADD	RAX, t		;Moving variable into RAX

	MOV	RAX, [RAX]
	PRINT_DEC  8, RAX	;Printing a number.
	NEWLINE

	mov	rbp,[rsp]	;FUNC end restore old BP
	mov	rsp,[rsp+8]	;FUNC end restore old SP
	mov	rsp,rbp		;stack and BP need to be same on exit for main
	xor	rax, rax		; no value specificed, then it is 0
	ret
