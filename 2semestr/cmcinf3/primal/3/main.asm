%include "io.inc"

section .bss
    n resd 1
    a resd 500010
    min resd 500010
    max resd 500010
    
section .data
    min_count dd 0
    max_count dd 0

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
            
    GET_DEC 4, [n]
    mov ecx, dword[n]
    cmp ecx, 2
    jbe break
    
    lop1:
        GET_DEC 4, [a + ecx * 0x4]
    loop lop1
    
    mov ecx, dword[n]
    dec ecx
        
    lop2:
        cmp ecx, 1
        je break
        
        mov eax, dword[a + ecx * 0x4]
        mov ebx, dword[a + ecx * 0x4 + 0x4]
        cmp eax, ebx
        jg A
        jl B
        jmp R
        A:
            mov ebx, dword[a + ecx * 0x4 - 0x4]
            cmp eax, ebx
            jg C
            jmp R
            C:
            mov edx, dword[max_count]
            mov eax, [n]
            sub eax, ecx
            mov dword[max + edx * 0x4], eax
            inc dword[max_count]
            jmp R
        B:
            mov ebx, dword[a + ecx * 0x4 - 0x4]
            cmp eax, ebx
            jl D
            jmp R
            D:
            mov edx, dword[min_count]
            mov eax, [n]
            mov [min + edx * 0x4], eax
            sub dword[min + edx * 0x4], ecx
            inc dword[min_count]
            jmp R
        R:
        dec ecx
    jmp lop2
    
    break:
    
    PRINT_DEC 4, [min_count]
    mov ecx, [min_count]
    cmp ecx, 0
    je break1
    NEWLINE
    mov edx, 0x0
    lop3:
        cmp ecx, 0
        je break1
        PRINT_DEC 4, [min + edx]
        PRINT_CHAR ' '
        add edx, 0x4
        dec ecx
    jmp lop3
    break1:
    NEWLINE
    PRINT_DEC 4, [max_count]
    mov ecx, [max_count]
    cmp ecx, 0
    je break2
    NEWLINE
    mov edx, 0x0
    lop4:
        cmp ecx, 0
        je break2
        PRINT_DEC 4, [max + edx]
        PRINT_CHAR ' '
        add edx, 0x4
        dec ecx
    jmp lop4
    break2:
    
    ;write your code here
    xor eax, eax
    ret
