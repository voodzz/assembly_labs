.686
PUBLIC _calculateTask1
.model flat

.data
tmp_ dw ?

.code
_calculateTask1 proc
  push ebp
  mov ebp, esp
  
  finit
  fld dword ptr[ebp + 8] ; x
  fld dword ptr[ebp + 12] ; y
  fdiv ST(1), ST(0)
  fld dword ptr[ebp + 8]
  fdiv ST(1), ST(0)
  fstp dword ptr[tmp_]
  fadd ST(0), ST(1)
  fcos
  
  fld dword ptr[ebp + 8] ; x
  fld dword ptr[ebp + 12] ; y
  fsub ST(1), ST(0)
  fstp dword ptr[tmp_]
  fabs
  fmul ST(0), ST(1)

  mov esp, ebp
  pop ebp
  ret
_calculateTask1 endp
end
