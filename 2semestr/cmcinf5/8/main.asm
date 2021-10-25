%include "io.inc"

section .data
	msg1 db "%d", 0
	msg2 db "%d ", 0
	pathin db "input.txt", 0
	pathout db "output.txt", 0
	openr db "r", 0
	openw db "w", 0

section .bss
	a resd 10000

CEXTERN qsort
CEXTERN fopen
CEXTERN fscanf
CEXTERN fprintf
CEXTERN fclose

section .text
global CMAIN
CMAIN:
	push ebp
	mov ebp, esp

	;link on file
	;size
	;tmp

	sub esp, 0xc

	and esp, ~0xf
	sub esp, 0x10
;input
	mov dword[esp], pathin
	mov dword[esp + 0x4], openr
	call fopen

	mov dword[ebp - 0x4], eax
	xor ecx, ecx
.L1:
	mov dword[ebp - 0x8], ecx
	;fscanf
	mov eax, dword[ebp - 0x4]
	mov dword[esp], eax
	mov dword[esp + 0x4], msg1
	lea ebx, [ebp - 0xc]
	mov dword[esp + 0x8], ebx
	call fscanf
	cmp eax, 0x1
	jne .end1
	mov ecx, dword[ebp - 0x8]
	mov eax, dword[ebp - 0xc]
	mov dword[a + ecx * 0x4], eax
	inc ecx
	mov dword[ebp - 0x8], ecx
	jmp .L1
.end1:
	mov eax, dword[ebp - 0x4]
	mov dword[esp], eax
	call fclose
;qsort
	mov eax, a
	mov dword[esp], eax
	mov eax, dword[ebp - 0x8]
	mov dword[esp + 0x4], eax
	mov dword[esp + 0x8], 0x4
	mov dword[esp + 0xc], compare
	call qsort

;output
	mov dword[esp], pathout
	mov dword[esp + 0x4], openw
	call fopen

	mov dword[ebp - 0x4], eax
	xor ecx, ecx
.L2:
	mov dword[ebp - 0xc], ecx
	;fprintf
	mov eax, dword[a + ecx * 0x4]
	mov dword[esp + 0x8], eax
	mov dword[esp + 0x4], msg2
	mov eax, dword[ebp - 0x4]
	mov dword[esp], eax
	call fprintf
	mov ecx, dword[ebp - 0xc]
	inc ecx
	cmp ecx, dword[ebp - 0x8]
	jne .L2

	mov eax, dword[ebp - 0x4]
	mov dword[esp], eax
	call fclose

	mov esp, ebp
	pop ebp
	xor eax, eax
	ret

compare:
	push ebp
	mov ebp, esp
	push ebx

	mov ebx, dword[ebp + 0xc]
	mov eax, dword[ebp + 0x8]
	
	mov eax, dword[eax]
	mov ebx, dword[ebx]

	cmp eax, ebx
	je .O
	jg .l
	xor eax, eax
	sub eax, 0x1
	jmp .end
.O:
	xor eax, eax
	jmp .end
.l:
	mov eax, 0x1
.end:
	pop ebx
	mov esp, ebp
	pop ebp
	ret
