%include "io.inc"

section .data
	msg1 db "%d", 0
	msg2 db "%d ", 0
	msg3 db `\n`, 0
	pathin db "input.bin", 0
	pathout db "output.bin", 0
	openr db "rb", 0
	openw db "wb", 0
	N equ 10000

section .bss
	len resd N
	a resd 30000
	n resd 1

CEXTERN fopen
CEXTERN printf
CEXTERN fread
CEXTERN fprintf
CEXTERN fclose

section .text
global CMAIN
CMAIN:
	push ebp
	mov ebp, esp

	;file
	;tmp
	;ecx

	xor ecx, ecx
.clear:
	mov dword[len + ecx * 0x4], 0x0
	inc ecx
	cmp ecx, N
	jne .clear

	sub esp, 0xc
	and esp, ~0xf
	sub esp, 0x10
;input
	mov dword[esp], pathin
	mov dword[esp + 0x4], openr
	call fopen

	xor ecx, ecx
	mov dword[ebp - 0x4], eax
.L1:
	mov dword[ebp - 0xc], ecx
	lea eax, [ebp - 0x8]
	mov dword[esp], eax
	mov dword[esp + 0x4], 0x4
	mov dword[esp + 0x8], 0x1
	mov eax, dword[ebp - 0x4]
	mov dword[esp + 0xc], eax
	call fread

	cmp eax, 0x1
	jne .end

	mov eax, dword[ebp - 0x8]
	mov ecx, dword[ebp - 0xc]
	mov dword[a + ecx * 0x4], eax
	inc ecx
	mov dword[n], ecx
	jmp .L1

.end:
	mov eax, dword[ebp - 0x4]
	mov dword[esp], eax
	call fclose
;building

	mov eax, dword[n]
	cdq
	mov ecx, 0x3
	idiv ecx
	mov dword[n], eax
	xor ecx, ecx
.L:
	imul ebx, ecx, 0xc
	add ebx, a
	add ebx, 0x4
	cmp dword[ebx], ~0x0
	je .end1
	imul edx, ecx, 0xc
	sub dword[ebx], edx
	sub dword[ebx], 0x4
	add dword[ebx], ebx
.end1:
	inc ecx
	cmp ecx, dword[n]
	jne .L
        xor ecx, ecx
.l:
	imul ebx, ecx, 0xc
	add ebx, a
	add ebx, 0x8
	cmp dword[ebx], ~0x0
        je .end2
        imul edx, ecx, 0xc
        sub dword[ebx], edx
	sub dword[ebx], 0x8
        add dword[ebx], ebx
.end2:
        inc ecx
        cmp ecx, dword[n]
        jne .l

;	rec - output
;	len - calculating height of this tree
	xor ecx, ecx
.L2:
	push ecx
	cmp dword[len + ecx * 0x4], 0x0
	jne .endL2
	push len
	push a
	imul eax, ecx , 0xc
	add eax, a
	push eax
	call lenfunc
	add esp, 0xc
.endL2:
	pop ecx
	inc ecx
	cmp ecx, dword[n]
	jne .L2

	xor ecx, ecx
	xor edx, edx
.L3:
	mov eax, dword[len + edx * 0x4]
	cmp eax, dword[len + ecx * 0x4]
	jnl .endL3
	mov edx, ecx
.endL3:
	inc ecx
	cmp ecx, dword[n]
	jne .L3

	mov dword[ebp - 0x8], edx

;output

	imul eax, dword[ebp - 0x8], 0xc
	add eax, a
	push msg2
	push eax
	call rec
	add esp, 0x8

	mov esp, ebp
	pop ebp
	xor eax, eax
	ret

lenfunc:
	push ebp
	mov ebp, esp
	push ebx

	;link on len[0]
	;link on a[0]
	;link on node

	mov eax, dword[ebp + 0x8]
	sub eax, dword[ebp + 0xc]
	cdq
	mov ecx, 0xc
	idiv ecx
	mov edx, dword[ebp + 0x10]
	cmp dword[edx + eax * 0x4], 0x0
	jne .end
	mov dword[edx + eax * 0x4], 0x1
	mov eax, dword[ebp + 0x8]
	add eax, 0x4
	cmp dword[eax], ~0x0
	je .L
	mov ecx, dword[ebp + 0x10]
	push ecx
	mov ecx, dword[ebp + 0xc]
	push ecx
	push dword[eax]
	call lenfunc

	add esp, 0xc
	mov eax, dword[ebp + 0x8]
	add eax, 0x4
	mov eax, dword[eax]
	sub eax, dword[ebp + 0xc]
	cdq
	mov ecx, 0xc
	idiv ecx
	mov ebx, eax ;son

	mov eax, dword[ebp + 0x8]
	sub eax, dword[ebp + 0xc]
	cdq
	mov ecx, 0xc
	idiv ecx
	mov edx, dword[ebp + 0x10]
	mov ecx, dword[edx + ebx * 0x4] ;son
	add dword[edx + eax * 0x4], ecx

.L:
	mov eax, dword[ebp + 0x8]
	add eax, 0x8
	cmp dword[eax], ~0x0
	je .end
        mov ecx, dword[ebp + 0x10]
        push ecx
        mov ecx, dword[ebp + 0xc]
        push ecx
        push dword[eax]
        call lenfunc

        add esp, 0xc
        mov eax, dword[ebp + 0x8]
      	add eax, 0x8
	mov eax, dword[eax]
        sub eax, dword[ebp + 0xc]
        cdq
        mov ecx, 0xc
        idiv ecx
        mov ebx, eax ;son

        mov eax, dword[ebp + 0x8]
        sub eax, dword[ebp + 0xc]
        cdq
        mov ecx, 0xc
        idiv ecx
	mov edx, dword[ebp + 0x10]
        mov ecx, dword[edx + ebx * 0x4] ;son
        add dword[edx + eax * 0x4], ecx
.end:
	pop ebx
	mov esp, ebp
	pop ebp
	ret

out:
	push ebp
	mov ebp, esp

	;msg
	;link on memory
	and esp, ~0xf
	sub esp, 0x10
	mov eax, dword[ebp + 0xc]
	mov dword[esp], eax
	mov eax, dword[ebp + 0x8]
	mov eax, dword[eax]
	mov dword[esp + 0x4], eax
	call printf

	mov esp, ebp
	pop ebp
	ret

rec:
	push ebp
	mov ebp, esp
	;msg
	;link

	mov ecx, dword[ebp + 0xc]
	push ecx
	mov eax, dword[ebp + 0x8]
	push eax
	call out
	add esp, 0x8
	mov eax, dword[ebp + 0x8]
	add eax, 0x4
	cmp dword[eax], ~0x0
	je .end1
	mov ecx, dword[esp + 0xc]
	push ecx
	push dword[eax]
	call rec
	add esp, 0x8
.end1:

	mov eax, dword[ebp + 0x8]
	add eax, 0x8
	cmp dword[eax], ~0x0
	je .end2
	mov ecx, dword[ebp + 0xc]
	push ecx
	push dword[eax]
	call rec
	add esp, 0x8
.end2:

	mov esp, ebp
	pop ebp
	ret
