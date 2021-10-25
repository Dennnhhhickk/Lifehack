%include "io.inc"

section .data
	msg1 db "%u", 0
	msg2 db `0x%08X\n`, 0

CEXTERN printf
CEXTERN scanf

section .text
global CMAIN
CMAIN:
	push ebp
	mov ebp, esp

	sub esp, 0x4
	and esp, ~0xf
	sub esp, 0x10
.L1:
	mov dword[esp], msg1
	lea ecx, [ebp - 0x4]
	mov dword[esp + 0x4], ecx
	call scanf

	cmp eax, 0x1
	jne .end

	mov eax, dword[ebp - 0x4]

	mov dword[esp], msg2
	mov dword[esp + 0x4], eax
	call printf
	jmp .L1
.end:
	mov esp, ebp
	pop ebp
	xor eax, eax
	ret 
