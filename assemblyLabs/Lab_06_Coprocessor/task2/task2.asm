.686
PUBLIC _findRoot
.model flat

.data
fa dq ?
fc dq ?
a dq -10.0
b dq 10.0
c_ dq ?
two dd 2
four dd 4
eleven dd 11
pointTwo dq -0.2
trash dq ?
length_ dq ?
precision dq 0.0001


.code
_findRoot proc
push ebp
mov ebp, esp

finit
while_:
; point c
fld a
fld b
fadd ST(0), ST(1)
fild two
fdiv ST(1), ST(0)
fstp [trash]
fstp qword ptr[c_]
fstp [trash]

; f(a)
fld a
fld a
fmul ST(0), ST(1)
fld pointTwo
fmul ST(0), ST(1)
fild four
fadd ST(1), ST(0)
fistp [trash]
fild eleven
fadd ST(0), ST(3)
fdiv ST(1), ST(0)
fild two
fadd ST(0), ST(2)
fstp qword ptr[fa]
fstp [trash]
fstp [trash]
fstp [trash]
fstp [trash]

; f(c)
fld c_
fld c_
fmul ST(0), ST(1)
fld pointTwo
fmul ST(0), ST(1)
fild four
fadd ST(1), ST(0)
fistp [trash]
fild eleven
fadd ST(0), ST(3)
fdiv ST(1), ST(0)
fild two
fadd ST(0), ST(2)
fstp qword ptr[fc]
fstp [trash]
fstp [trash]
fstp [trash]
fstp [trash]

; b-a (length_)
fld a
fld b
fsub ST(0), ST(1)
fstp qword ptr [length_]
fstp [trash]

; compare with needed precision
fld length_
fld precision
fcom
fstsw ax
sahf
ja out_
fstp[trash]
fstp[trash]


; f(a) * f(c)
fldz
fld fc
fld fa
fmul ST(0), ST(1)
fcom ST(2)
fstsw ax
sahf
jb bChange_
ja aChange_

bChange_ :
	fld c_
	fstp qword ptr[b]
	fld b
	fstp[trash]
	fstp[trash]
	fstp[trash]
	jmp while_

aChange_ :
	fld c_
	fstp qword ptr[a]
	fstp[trash]
	fstp[trash]
	fstp[trash]
	jmp while_

out_:
fld c_
mov esp, ebp
pop ebp
ret
_findRoot endp
end