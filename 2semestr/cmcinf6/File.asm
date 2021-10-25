section .data
	const1 dq 0.35
	const2 dq 0.95
	const3 dq 2.7
	const4 dq 3.0
	const5 dq 2.0
	const6 dq 5.0

section .text
GLOBAL f1
GLOBAL f2
GLOBAL f3
f1:
	push ebp
	mov ebp, esp

	finit
	fld qword[ebp + 0x8]
	fld qword[ebp + 0x8]
	fld qword[const1]
	fmulp
	fmulp
	fld qword[ebp + 0x8]
	fld qword[const2]
	fmulp
	fsubp
	fld qword[const3]
	faddp

	mov esp, ebp
	pop ebp
	ret

f2:
	push ebp
	mov ebp, esp

	finit
	fld qword[ebp + 0x8]
	fld qword[const4]
	fmulp
	fld1
	faddp

	mov esp, ebp
	pop ebp
	ret

f3:
	push ebp
	mov ebp, esp

	finit
	fld1
	fld qword[ebp + 0x8]
	fld qword[const5]
	faddp
	fdivp

	mov esp, ebp
	pop ebp
	ret
