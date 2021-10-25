%include "io.inc"

section .bss
a resd 2

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    GET_DEC 4, [a]
    GET_DEC 4, [a+0x4]
    
    mov eax, [a]
    dec eax
    cdq
    mov ebx, 0x2
    idiv ebx
    
    mov ebx, eax
    mov ecx, edx
    mov eax, 42
    cdq
    imul ebx
    
    mov [a], eax
    mov eax, 41
    add ebx, ecx
    cdq
    imul ebx
    add eax, [a]
    add eax, [a+0x4]
    
    PRINT_DEC 4, eax
    
    xor eax, eax
    ret
