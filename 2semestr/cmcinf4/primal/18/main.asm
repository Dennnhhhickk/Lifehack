%include "io.inc"

section .bss
	N equ 10000
	M equ 1000000000
	TEN equ 10
	a resd N
	sign resd 1
	bol resd 1
	lastbol resd 1

section .text
global CMAIN
CMAIN:
	xor eax, eax
.L1:
	mov dword[a + eax * 0x4], 0x0
	inc eax
	cmp eax, N
	jb .L1
	
	mov dword[sign], 0x1
	mov dword[a], 0x1

	push a
	push dword[sign]
	call container
	mov dword[sign], eax
	add esp, 0x8
	push a
	push dword[sign]
	call container
	mov dword[sign], eax
	add esp, 0x8
	push a
	push dword[sign]
	call container
	mov dword[sign], eax
	add esp, 0x8

	mov dword[bol], 0x0
	mov dword[lastbol], 0x0
	cmp dword[sign], 0x1
	je .L0
	PRINT_CHAR '-'
.L0:
	
	xor eax, eax
	mov ecx, N
.L2:
	cmp ecx, 0x1
	push ecx
	jne .l2
	mov dword[bol], 0x1
.l2:
	cmp dword[a + ecx * 0x4 - 0x4], 0x0
	je .L3
	mov dword[bol], 0x1
.L3:
	cmp dword[bol], 0x1
	jne .L4
	cmp dword[lastbol], 0x1
	jne .l21

	push dword[a + ecx * 0x4 - 0x4]
	push 0x8
	call rec
	pop edx
	pop edx
	jmp .L4
.l21:
	PRINT_UDEC 0x4, [a + ecx * 0x4 - 0x4]
.L4:
	mov eax, dword[bol]
	mov dword[lastbol], eax
	pop ecx
	dec ecx
	cmp ecx, 0x0
	jne .L2

	xor eax, eax
	ret

container:
	push ebp
	mov ebp, esp
	push ebx

	GET_DEC 0x4, eax
	mov ebx, eax
	sar ebx, 0x1f
	inc ebx
	imul ecx, ebx, 0x2
	dec ecx
	cdq
	imul ecx
	mov ebx, eax
	push ecx
	mov edx, dword[ebp + 0xc]
	push edx
	push ebx
	call multi
	add esp, 0x8
	pop ecx
	mov eax, dword[ebp + 0x8]
	cdq
	imul ecx

	pop ebx
	mov esp, ebp
	pop ebp
	ret

rec:
	push ebp
	mov ebp, esp
	push ebx

	cmp dword[ebp + 0x8], 0x0
	je .L1
	mov eax, dword[ebp + 0xc]
	cdq
	push ebx
	mov ebx, TEN
	div ebx
	pop ebx
	push eax
	mov ebx, dword[ebp + 0x8]
	dec ebx
	push ebx
	call rec
	pop ebx
	pop eax
.L1:
	mov eax, dword[ebp + 0xc]
	cdq
	push ebx
	mov ebx, TEN
	div ebx
	pop ebx
	PRINT_DEC 4, edx

	pop ebx
	mov esp, ebp
	pop ebp
	ret

multi:
	push ebp
	mov ebp, esp
	push esi
	push ebx

	mov esi, dword[ebp + 0x8]
	xor ecx, ecx
	xor ebx, ebx
.L1:
	mov edx, dword[ebp + 0xc]
	mov eax, dword[edx + ecx * 0x4]
	mov edx, eax
	cdq
	mul esi
	add eax, ebx
	adc edx, 0x0
	push ebx
	mov ebx, M
	div ebx
	pop ebx
	mov ebx, dword[ebp + 0xc]
	mov dword[ebx + ecx * 0x4], edx
	mov ebx, eax

	inc ecx
	cmp ecx, N
	jb .L1

	pop ebx
	pop esi
	mov esp, ebp
	pop ebp
	ret
