%include "io.inc"

section .data
	M dd 2011

section .bss
	k resd 1
	n resd 1
	a resd 1
	x resd 2

section .text
global CMAIN
CMAIN:
	GET_DEC 0x4, k
	GET_DEC 0x4, n
	GET_DEC 0x4, a

	mov eax, dword[a]
	cdq
	idiv dword[M]
	mov dword[x], edx
	mov dword[x + 0x4], edx

	cmp dword[n], 0
	je .end

	xor ecx, ecx
.L1:
	push ecx
	push dword[k]
	push dword[x] 		;D
	push dword[x + 0x4]	;C
	call func
	add esp, 0xc
	pop ecx	

	cdq
	idiv dword[M]
	mov eax, dword[x]

	xor eax, dword[x + 0x4]
	xor dword[x + 0x4], eax
	xor eax, dword[x + 0x4]
	
	mov dword[x], edx
	inc ecx
	cmp ecx, dword[n]
	jne .L1

.end:
	PRINT_DEC 0x4, x

	xor eax, eax
	ret

step:
	push ebp
	mov ebp, esp

	push ebx

	mov eax, dword[ebp + 0x8]
	xor ebx, ebx
.L1:
	cdq
	idiv dword[ebp + 0xc]
	inc ebx
	cmp eax, 0x0
	jne .L1

	mov eax, ebx

	pop ebx

	mov esp, ebp
	pop ebp
	ret

func:
	push ebp
	mov ebp, esp

	push dword[ebp + 0x10]
	push dword[ebp + 0x8]
	call step
	sub esp, 0x8

	mov ecx, eax
	mov eax, 0x1
	cdq
.L1:
	mul dword[ebp + 0x10]
	loop .L1

	mul dword[ebp + 0xc]
	add eax, dword[ebp + 0x8]

	mov esp, ebp
	pop ebp
	ret
