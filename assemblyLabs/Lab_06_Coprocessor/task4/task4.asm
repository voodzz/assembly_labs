.686
PUBLIC _ln2
.model flat

.data
k dd ?
result dq 0
trash dd ?

.code
_ln2 proc
push ebp
mov ebp, esp

finit
fild dword ptr[ebp + 8]
fistp dword ptr[k]
series_:
	fld1
	mov eax, k
	mov ebx, 2
	cdq
	idiv ebx
	cmp edx, 0
	je changeSign_
	jmp skip_

changeSign_:
	fchs

skip_:
	fild k
	fdiv ST(1), ST(0)
	fstp dword ptr[trash]
	fadd result
	fstp qword ptr[result]
	dec k
	mov eax, k
	cmp eax, 0
	je out_
	jne series_

out_:
	fld result
	mov esp, ebp
	pop ebp
	ret
_ln2 endp
end