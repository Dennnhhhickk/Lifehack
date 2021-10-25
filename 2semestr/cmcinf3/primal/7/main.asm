%include "io.inc"

section .bss
    n resd 1
    a resd 10010

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    GET_DEC 4, [n]
    
    mov ecx, 0
    INN:
        GET_DEC 4, [a + 0x4 * ecx]
    inc ecx
    cmp ecx, [n]
    jl INN
    
    ;SORT
    mov eax, 0
    first:
    
        mov ebx, 0
        second:
            mov edx, [a + eax * 0x4]
            mov ecx, [a + ebx * 0x4]
            cmp edx, ecx
            jge f
            mov [a + eax * 0x4], ecx
            mov [a + ebx * 0x4], edx
            f:
        inc ebx
        cmp ebx, [n]
        jl second
            
    
    inc eax
    cmp eax, [n]
    jl first
    ;SORT
    
    mov ecx, 0
    OUTT:
        PRINT_DEC 4, [a + 0x4 * ecx]
        PRINT_CHAR ' '
    inc ecx
    cmp ecx, [n]
    jl OUTT 

    xor eax, eax
    ret
