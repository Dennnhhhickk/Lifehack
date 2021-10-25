%include "io.inc"

section .bss
a resd 5

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    GET_DEC 4, [a]
    GET_DEC 4, [a+0x4]
    GET_DEC 4, [a+0x8]
    GET_DEC 4, [a+0x10]
    GET_DEC 4, [a+0x14]
    
    mov ecx, 0x8
    
    mov eax, [a+ecx]
    cdq
    mov ebx, [a+0x14]
    mul ebx
    mul ebx
    mov [a+ecx], eax
    mov eax, [a]
    mul ebx
    add [a+ecx], eax
    
    PRINT_DEC 4, [a+ecx]
    PRINT_CHAR ' '
    
    mov ecx, 0x10
    
    mov eax, [a+ecx]
    cdq
    mov ebx, [a+0x14]
    mul ebx
    mul ebx
    mov [a+ecx], eax
    mov eax, [a+0x4]
    mul ebx
    add [a+ecx], eax
    
    PRINT_DEC 4, [a+ecx]
    
    xor eax, eax
    ret
