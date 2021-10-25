%include "io.inc"

section .bss
    a resd 2
    
section .data
    b dd 'H', '8'

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    GET_CHAR [a]
    GET_CHAR [a+0x4]
    
    mov eax, [a]
    sub eax, [b]
    mov ebx, eax
    mov eax, [a+0x4]
    sub eax, [b+0x4]
    cdq
    imul ebx
    mov ebx, 0x2
    cdq
    idiv ebx
    
    PRINT_DEC 4, eax
    
    xor eax, eax
    ret
