%include "io.inc"

section .bss
    k resd 1
    tmp resd 1
    
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging

    GET_DEC 4, k

    xor eax, eax
    xor ebx, ebx
    
.l1:
        
    inc eax
    push ebx
    push eax
    call check
    mov ecx, eax
    
    pop eax
    pop ebx    
    
    cmp eax, ecx
    jng .end1
    inc ebx
.end1:
    cmp ebx, dword[k]
    je .end
    jmp .l1
.end:
    PRINT_DEC 4, eax
    xor eax, eax
    ret
    
check:
    push ebp
    mov ebp, esp
    
    mov dword[tmp], eax
    
    cmp eax, 1
    je .end
    
    xor ecx, ecx
    xor ebx, ebx
    mov ecx, 1
.L1:
    mov eax, dword[tmp]
    mov edx, eax
    cdq
    idiv ecx
    cmp edx, 0
    jne .L2
    add ebx, ecx
.L2:
    inc ecx
    cmp ecx, dword[tmp]
    jl .L1
.end:
    mov eax, ebx
    mov esp, ebp
    pop ebp
    ret
    
