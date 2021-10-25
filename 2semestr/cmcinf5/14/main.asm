%include "io.inc"

section .data
	msg1 db "%d", 0
	msg2 db "%d ", 0
	msg3 db `\n`, 0
	pathin db "input.txt", 0
	pathout db "output.txt", 0
	openr db "r", 0
	openw db "w", 0

section .bss
	n resd 1

CEXTERN fopen
CEXTERN fprintf
CEXTERN fscanf
CEXTERN fclose
CEXTERN malloc
CEXTERN free

section .text
global CMAIN
CMAIN:
	push ebp
	mov ebp, esp

	;link on file
	;link on head element
	;tmp

	mov dword[n], 0
	sub esp, 0xc
	and esp, ~0xf
	sub esp, 0x10

	mov dword[ebp - 0x8], 0x0

;input
	mov dword[esp], pathin
	mov dword[esp + 0x4], openr
	call fopen

	mov dword[ebp - 0x4], eax

.L1:
	mov eax, dword[ebp - 0x4]
	mov dword[esp], eax
	mov dword[esp + 0x4], msg1
	lea eax, [ebp - 0xc]
	mov dword[esp + 0x8], eax
	call fscanf

	cmp eax, 0x1
	jne .end

	mov eax, dword[n]
	inc eax
	mov dword[n], eax

	mov eax, dword[ebp - 0xc]
	push eax
	mov eax, dword[ebp - 0x8]
	push eax
	call addd
	mov dword[ebp - 0x8], eax
	add esp, 0x8

	jmp .L1

.end:
	mov eax, dword[ebp - 0x4]
	mov dword[esp], eax
	call fclose

;sort
	xor ecx, ecx
.Lop:
	mov dword[ebp - 0xc], ecx
	mov eax, dword[ebp - 0x8]
	mov dword[esp], eax
	call sort
	mov ecx, dword[ebp - 0xc]
	inc ecx
	cmp ecx, dword[n]
	jne .Lop

;output
	mov dword[esp], pathout
	mov dword[esp + 0x4], openw
	call fopen

	push msg3
	push msg2
	mov dword[ebp - 0x4], eax
	push eax
	mov eax, dword[ebp - 0x8]
	push eax
	call fout
	add esp, 0x10

	mov eax, dword[ebp - 0x4]
	mov dword[esp], eax
	call fclose

	mov esp, ebp
	pop ebp
	xor eax, eax
	ret

sort:
	push ebp
	mov ebp, esp

	mov eax, dword[ebp + 0x8]
	cmp eax, 0x0
	je .end
	mov ecx, eax
	add ecx, 0x4
	mov ecx, dword[ecx]
	cmp ecx, 0x0
	je .end
	mov edx, dword[ecx]
	cmp dword[eax], edx
	jng .L
	mov edx, dword[eax]
	xor edx, dword[ecx]
	xor dword[ecx], edx
	xor edx, dword[ecx]
	mov dword[eax], edx
.L:
	push ecx
	call sort
.end:
	mov esp, ebp
	pop ebp
	ret

new:
	push ebp
	mov ebp, esp

	and esp, ~0xf
	sub esp, 0x10
	mov dword[esp], 0x8
	call malloc

	mov esp, ebp
	pop ebp
	ret

addd:
	push ebp
	mov ebp, esp
	push ebx

	mov eax, dword[ebp + 0x8]
	mov ebx, dword[ebp + 0xc]

	cmp eax, 0x0
	jne .rec

	call new
	mov dword[eax], ebx
	mov ecx, eax
	add ecx, 0x4
	mov dword[ecx], 0x0

	jmp .end
.rec:
	mov ecx, eax
	mov ecx, dword[ecx]
	push ebx
	add eax, 0x4
	mov eax, dword[eax]
	push eax
	call addd
	add esp, 0x8

	mov ecx, dword[ebp + 0x8]
	add ecx, 0x4
	mov dword[ecx], eax
	mov eax, dword[ebp + 0x8]
.end:

	pop ebx
	mov esp, ebp
	pop ebp
	ret

print:
	push ebp
	mov ebp, esp

	;msg
	;value
	;file

	mov eax, dword[ebp + 0x8]
	mov ecx, dword[ebp + 0xc]

	and esp, ~0xf
	sub esp, 0x10
	mov dword[esp], eax
	mov eax, dword[ebp + 0x10]
	mov dword[esp + 0x4], eax
	mov dword[esp + 0x8], ecx
	call fprintf

	mov esp, ebp
	pop ebp
	ret

line:
	push ebp
	mov ebp, esp

	and esp, ~0xf
	sub esp, 0x10
	mov eax, dword[ebp + 0xc]
	mov dword[esp + 0x4], eax
	mov ecx, dword[ebp + 0x8]
	mov dword[esp], ecx
	call fprintf

	mov esp, ebp
	pop ebp
	ret

FREE:
	push ebp
	mov ebp, esp

	and esp, ~0xf
	sub esp, 0x10
	mov eax, dword[ebp + 0x8]
	mov dword[esp], eax
	call free

	mov esp, ebp
	pop ebp
	ret

fout:
	push ebp
	mov ebp, esp

	;line
	;msg
	;file
	;head

	mov eax, dword[ebp + 0x8]
	cmp eax, 0x0
	je .L
	mov edx, dword[eax]

	mov ecx, dword[ebp + 0xc]
	mov eax, dword[ebp + 0x10]
	push eax
	push edx
	push ecx
	call print
	add esp, 0xc

	mov ecx, dword[ebp + 0x14]
	push ecx
	mov ecx, dword[ebp + 0x10]
	push ecx
	mov ecx, dword[ebp + 0xc]
	push ecx
	mov eax, dword[ebp + 0x8]
	add eax, 0x4
	mov eax, dword[eax]
	push eax
	call fout
	add esp, 0x10

	mov eax, dword[ebp + 0x8]
	push eax
	call FREE
	add esp, 0x4

	jmp .end
.L:
	mov ecx, dword[ebp + 0x14]
	push ecx
	mov ecx, dword[ebp + 0xc]
	push ecx
	call line
.end:
	mov esp, ebp
	pop ebp
	xor eax, eax
	ret
