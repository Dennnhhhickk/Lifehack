%include "io.inc"

section .bss
	n resd 0x1
	a resd 0x1
	b resd 0x1

section .text
global CMAIN
CMAIN:
	GET_DEC 0x4, n
	xor ecx, ecx
	mov dword[a], 0x0
	mov dword[b], 0x1
.L1:
	GET_DEC 0x4, eax
	GET_DEC 0x4, ebx

	push ecx
	push dword[a]
	push dword[b]
	call sum
	call sokrat
	pop dword[b]
	pop dword[a]
	pop ecx

	inc ecx
	cmp ecx, dword[n]
	je .end
	jmp .L1
.end:

	PRINT_DEC 0x4, a
	PRINT_CHAR ' '
	PRINT_DEC 0x4, b
	xor eax, eax
	ret

sokrat:
	push ebp
	mov ebp, esp

	push ebx

	mov eax, dword[ebp + 0xc]
	mov ebx, dword[ebp + 0x8]
	
	push eax
	push ebx
	call HOD
	pop ebx
	pop eax
	mov ecx, eax

	mov eax, dword[ebp + 0xc]
	mov edx, eax
	cdq
	idiv ecx
	mov dword[ebp + 0xc], eax

	mov eax, dword[ebp + 0x8]
	mov edx, eax
	cdq
	idiv ecx
	mov dword[ebp + 0x8], eax

	pop ebx

	mov esp, ebp
	pop ebp
	ret

HOD:
	push ebp
	mov ebp, esp
	push ebx

	mov eax, dword[ebp + 0xc]
	mov ebx, dword[ebp + 0x8]

.L1:
	cmp ebx, 0x0
	je .end

	mov edx, eax
	cdq
	idiv ebx
	mov eax, edx

	xor eax, ebx
	xor ebx, eax
	xor eax, ebx
	jmp .L1

.end:
	mov dword[ebp + 0x8], ebx
	mov dword[ebp + 0xc], eax
	pop ebx
	mov esp, ebp
	pop ebp
	ret

sum:
	push ebp
	mov ebp, esp

	push ebx

	imul eax, dword[ebp + 0x8]
	mov ecx, dword[ebp + 0xc]
	imul ecx, ebx
	add eax, ecx
	imul ebx, dword[ebp + 0x8]
	mov dword[ebp + 0xc], eax
	mov dword[ebp + 0x8], ebx

	pop ebx
	mov esp, ebp
	pop ebp
	ret
