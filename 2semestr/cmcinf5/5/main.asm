%include "io.inc"

section .data
	msg1 db "%d", 0
	msg2 db `\n`, 0

CEXTERN printf
CEXTERN scanf
CEXTERN malloc
CEXTERN realloc
CEXTERN reallocarray
CEXTERN free

section .text
global CMAIN
CMAIN:
	push ebp
	mov ebp, esp

	;link
	;size
	;k
	;tmp

	sub esp, 0x10
	and esp, ~0xf
	sub esp, 0x10
	mov dword[esp], 0x4
	call malloc

	mov dword[ebp - 0x4], eax
	mov dword[ebp - 0x8], 0x4
	mov dword[ebp - 0xc], 0x0
.L1:
	mov dword[esp], msg1
	lea ecx, [ebp - 0x10]
	mov dword[esp + 0x4], ecx
	call scanf

	mov eax, dword[ebp - 0x10]

	cmp eax, 0x0
	je .end

	mov ebx, dword[ebp - 0xc]
	mov ecx, dword[ebp - 0x4]
	mov dword[ecx + ebx], eax
	add ebx, 0x4
	mov dword[ebp - 0xc], ebx

	cmp ebx, dword[ebp - 0x8]
	jne .L2

;	mov dword[esp + 0x8], 0x4
	mov ebx, dword[ebp - 0x4]
	mov dword[esp], ebx
	imul ebx, dword[ebp - 0x8], 0x2
	mov dword[ebp - 0x8], ebx
	mov dword[esp + 0x4], ebx
	call realloc
	mov dword[ebp - 0x4], eax
.L2:

	jmp .L1
.end:

        mov eax, dword[ebp - 0x4]
        mov ecx, dword[ebp - 0xc]
        mov ebx, dword[eax + ecx - 0x4]
        xor ecx, ecx
        xor edx, edx
.L3:
        cmp dword[eax + ecx], ebx
        jnb .L4
        inc edx
.L4:
        add ecx, 0x4
        cmp ecx, dword[ebp - 0xc]
        jne .L3

	mov dword[esp], msg1
	mov dword[esp + 0x4], edx
	call printf

	mov eax, dword[ebp - 0x4]
	mov dword[esp], eax
	call free

	mov esp, ebp
	pop ebp
	xor eax, eax
	ret 
