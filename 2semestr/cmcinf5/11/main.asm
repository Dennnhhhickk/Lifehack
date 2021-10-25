%include "io.inc"

section .bss
	N equ 100010
	a resd N * 0x2
	n resd 1
	m resd 1
	l resd 1
	r resd 1
	pptr resd 1

section .data
	pathin db "input.txt", 0
	pathout db "output.txt", 0
	openr db "r", 0
	openw db "w", 0
	msg1 db "%d %d", 0
	msg2 db "%d ", 0

CEXTERN fscanf
CEXTERN fprintf
CEXTERN fopen
CEXTERN fclose

section .text
global CMAIN
CMAIN:
	push ebp
	mov ebp, esp

	mov dword[pptr], 0x0
	mov ecx, 0x1
.clear:
	imul eax, ecx, 0x8
	sub eax, 0x8
	add eax, a
	mov dword[a + ecx * 0x8], eax
	add eax, 0x10
	mov dword[a + ecx * 0x8 + 0x4], eax
	inc ecx
	cmp ecx, N
	jne .clear

	mov dword[a], 0x0
	mov dword[a + 0x4], 0x8
	mov eax, a
	add dword[a + 0x4], eax
	mov eax, N
	mov dword[a + eax * 0x8 - 0x4], 0x0

	sub esp, 0x4
	push openr
	push pathin
	call OPEN
	add esp, 0x8
	mov dword[ebp - 0x4], eax

	push m
	push n
	push msg1
	mov eax, dword[ebp - 0x4]
	push eax
	call IN
	add esp, 0x10

	mov eax, dword[n]
	mov dword[a + 0x8 * eax - 0x4], 0x0

	xor ecx, ecx
.L:
	push ecx
	push r
	push l
	push msg1
	mov eax, dword[ebp - 0x4]
	push eax
	call IN
	add esp, 0x10

	dec dword[r]
	dec dword[l]
;cut
	mov eax, dword[l]
	cmp dword[a + eax * 0x8], 0x0
	je .endL
	imul eax, dword[l], 0x8
	imul edx, dword[r], 0x8
	add eax, a
	add edx, a
	mov eax, dword[eax]
	add eax, 0x4
	add edx, 0x4
	mov ecx, dword[edx]
	mov dword[eax], ecx

	cmp dword[edx], 0x0
	je .endf
	imul eax, dword[l], 0x8
	imul edx, dword[r], 0x8
	add eax, a
	add edx, a
	add edx, 0x4

	mov edx, dword[edx]
	mov ecx, dword[eax]
	mov dword[edx], ecx
.endf:
;insert
	imul eax, dword[r], 0x8
	add eax, a
	imul edx, dword[pptr], 0x8
	add edx, a
	mov dword[edx], eax
	add eax, 0x4
	mov dword[eax], edx

	mov eax, dword[l]
	mov dword[pptr], eax
	imul eax, dword[l], 0x8
	add eax, a
	mov dword[eax], 0x0
.endL:

	pop ecx
	inc ecx
	cmp ecx, dword[m]
	jne .L

	mov eax, dword[ebp - 0x4]
	push eax
	call CLOSE
	add esp, 0x4

	push openw
	push pathout
	call OPEN
	add esp, 0x8
	mov dword[ebp - 0x4], eax

	push msg2
	mov eax, dword[ebp - 0x4]
	push eax
	push a
	xor ecx, ecx
.L1:
	cmp dword[a + ecx * 0x8], 0x0
	je .L1end
	inc ecx
	cmp ecx, dword[n]
	jne .L1
.L1end:
	imul eax, ecx, 0x8
	add eax, a
	push eax
	call rec
	add esp, 0x10

	mov eax, dword[ebp - 0x4]
	push eax
	call CLOSE

	mov esp, ebp
	pop ebp
	xor eax, eax
	ret

rec:
	push ebp
	mov ebp, esp

	;msg
	;file
	;a
	;left
	mov eax, dword[ebp + 0x8]
	sub eax, dword[ebp + 0xc]
	cdq
	mov ecx, 0x8
	idiv ecx

	inc eax
	push eax
	mov ecx, dword[ebp + 0x14]
	push ecx
	mov ecx, dword[ebp + 0x10]
	push ecx
	call OUT
	add esp, 0xc

	mov eax, dword[ebp + 0x8]
	add eax, 0x4
	cmp dword[eax], 0x0
	je .end
	mov eax, dword[ebp + 0x14]
	push eax
	mov eax, dword[ebp + 0x10]
	push eax
	mov eax, dword[ebp + 0xc]
	push eax
	mov eax, dword[ebp + 0x8]
	add eax, 0x4
	mov eax, dword[eax]
	push eax
	call rec
	add esp, 0x10
.end:
	mov esp, ebp
	pop ebp
	ret

OUT:
	push ebp
	mov ebp, esp

	and esp, ~0xf
	sub esp, 0x10
	mov eax, dword[ebp + 0x8]
	mov dword[esp], eax
	mov eax, dword[ebp + 0xc]
	mov dword[esp + 0x4], eax
	mov eax, dword[ebp + 0x10]
	mov dword[esp + 0x8], eax
	call fprintf

	mov esp, ebp
	pop ebp
	ret

IN:
	push ebp
	mov ebp, esp

	and esp, ~0xf
	sub esp, 0x10
	mov eax, dword[ebp + 0x8]
	mov dword[esp], eax
	mov eax, dword[ebp + 0xc]
	mov dword[esp + 0x4], eax
	mov eax, dword[ebp + 0x10]
	mov dword[esp + 0x8], eax
	mov eax, dword[ebp + 0x14]
	mov dword[esp + 0xc], eax
	call fscanf

	mov esp, ebp
	pop ebp
	ret

OPEN:
	push ebp
	mov ebp, esp

	and esp, ~0xf
	sub esp, 0x10
	mov eax, dword[ebp + 0x8]
	mov dword[esp], eax
	mov eax, dword[ebp + 0xc]
	mov dword[esp + 0x4], eax
	call fopen

	mov esp, ebp
	pop ebp
	ret

CLOSE:
	push ebp
	mov ebp, esp

	and esp, ~0xf
	sub esp, 0x10
	mov eax, dword[ebp + 0x8]
	mov dword[esp], eax
	call fclose

	mov esp, ebp
	pop ebp
	ret
