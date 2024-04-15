.686
PUBLIC _intgrl
.model flat

.data
pi dq ?
step dq ?
trash dq ?
k dd 10000000
x dq 0
sum dq 0
two dd 2
five dd 5

.code
_intgrl proc
push ebp
mov ebp, esp

finit
fldpi
fstp qword ptr[pi]

fldpi
fldpi
fadd ST(0), ST(1)
fild k
fdiv ST(1), ST(0)
fstp [trash]
fstp qword ptr[step]
fstp[trash]

mov ecx, k
loop_:
	fld x
	fld x
	fmul ST(0), ST(1)
	fsin
	fild five
	fmul ST(0), ST(2)
	fadd ST(0), ST(1)
	;fild two
	;fdiv ST(1), ST(0)
	;fstp [trash]
	fld sum
	fadd ST(0), ST(1)
	fstp qword ptr[sum]
	fstp [trash]
	fstp [trash]
	fld step
	fadd ST(0), ST(1)
	fstp qword ptr[x]
	fstp [trash]
	loop loop_

fld step
fld sum
fmul ST(0), ST(1)

mov esp, ebp
pop ebp
ret

_intgrl endp
end