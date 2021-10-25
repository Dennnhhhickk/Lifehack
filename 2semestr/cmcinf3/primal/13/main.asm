%include "io.inc"

section .bss
    n resd 1
    a resd 1000001
    k resd 1

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_UDEC 4, [n]
    
    cmp dword[n], 0
    je END1
    
    mov ecx, 0
    lop1:
        GET_UDEC 4, [a + 0x4 * ecx]
    inc ecx
    cmp ecx, dword[n]
    jb lop1
    
    GET_UDEC 4, [k]
    
    cmp dword[k], 0
    je END
    xor eax, eax
    lop2:
        xor ecx, ecx
        xor ebx, ebx
        lop3:
            mov edx, dword[a + ebx * 0x4]
            and edx, 1
            shr dword[a + ebx * 0x4], 1
            shl ecx, 31
            or dword[a + ebx * 0x4], ecx
            mov ecx, edx
            mov edx, [a + ebx * 0x4]
        inc ebx
        cmp ebx, dword[n]
        jb lop3
        
        shl ecx, 31
        or dword[a], ecx
        
        ;OUT
        ;mov edx, 0
        ;lop5:
        ;    PRINT_UDEC 4, [a + edx * 0x4]
        ;    PRINT_CHAR ' '
        ;inc edx
        ;cmp edx, [n]
        ;jb lop5
        ;NEWLINE
        ;OUT
        
    inc eax
    cmp eax, dword[k]
    jb lop2
    END:
    mov ecx, 0
    lop4:
        PRINT_UDEC 4, [a + ecx * 0x4]
        PRINT_CHAR ' '
    inc ecx
    cmp ecx, dword[n]
    jl lop4

    ;write your code here
    END1:
    xor eax, eax
    ret
