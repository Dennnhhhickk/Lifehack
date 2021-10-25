%include "io.inc"

section .bss
a resd 1

section .data
number dw '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'
suit dw 'S', 'C', 'D', 'H'

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    GET_DEC 4, [a]
    
    mov eax, [a]
    dec eax
    mov ebx, 13
    cdq
    idiv ebx
    
    mov ecx, eax
    mov eax, edx
    mov ebx, 0x2
    cdq
    imul ebx
    
    PRINT_CHAR [number + eax]
    
    mov eax, ecx
    cdq
    imul ebx
    
    PRINT_CHAR [suit + eax]
    
    xor eax, eax
    ret
