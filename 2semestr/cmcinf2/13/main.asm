%include "io.inc"

section .bss
    a resd 4

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    GET_CHAR [a]
    GET_CHAR [a+0x4]
    GET_CHAR [a+0x8]
    GET_CHAR [a+0x8]
    GET_CHAR [a+0xC]
    
    mov eax, [a+0x8]
    sub eax, [a]
    
    mov ebx, eax
    mov ecx, eax
    sar ebx, 0x1F
    mov eax, ebx
    inc eax
    mov ebx, 0x2
    imul ebx
    sub eax, 0x1
    mov ebx, eax
    mov eax, ecx
    imul ebx
    
    mov [a], eax
    
    mov eax, [a+0xC]
    sub eax, [a+0x4]
    
    mov ebx, eax
    mov ecx, eax
    sar ebx, 0x1F
    mov eax, ebx
    inc eax
    mov ebx, 0x2
    imul ebx
    sub eax, 0x1
    mov ebx, eax
    mov eax, ecx
    imul ebx
    
    add eax, [a]
    
    PRINT_DEC 4, eax
    
    xor eax, eax
    ret
