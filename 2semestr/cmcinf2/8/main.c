%include "io.inc"

section .bss
    a resd 3

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    GET_HEX 4, [a]
    GET_HEX 4, [a+0x4]
    GET_HEX 4, [a+0x8]
    
    mov eax, [a+0x8]
    and eax, [a]
    mov ecx, eax
    mov eax, [a+0x8]
    not eax
    and eax, [a+0x4]
    or eax, ecx
    
    PRINT_HEX 4, eax
    
    xor eax, eax
    ret
