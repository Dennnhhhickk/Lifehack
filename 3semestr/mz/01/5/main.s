.text
.globl exchange
exchange:
    pushl %ebp
    movl %esp, %ebp
    pushl %ebx
    pushl %esi
    pushl %edi

    xorl %ecx, %ecx
    pushl %eax
    pushl %edx

    movl %edx, %eax
    xorl %edx, %edx
    movl $2, %ebx
    divl %ebx
    movl %eax, %ebx

    popl %edx
    popl %eax
    cmpl $0, %ebx
    je .L1
.L0:
    dec %ebx
    leal (%eax, %ebx, 4), %esi
    movl %edx, %edi
    subl %ebx, %edi
    dec %edi
    leal (%eax, %edi, 4), %edi
    movl (%esi), %esi
    cmpl (%edi), %esi
    jb .L1

    leal  (%eax, %ebx, 4), %esi
    pushl %ebx
    movl (%esi), %ebx

    xorl (%edi), %ebx
    xorl %ebx, (%edi)
    xorl (%edi), %ebx

    movl %ebx, (%esi)

    popl %ebx

    inc %ecx
.L1:

    cmpl $0, %ebx
    jne .L0

    popl %edi
    popl %esi
    popl %ebx
    movl %ebp, %esp
    popl %ebp
    retl
