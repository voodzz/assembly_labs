.686
PUBLIC _isPalindrome
.model flat

.code
_isPalindrome proc
	push ebp
	mov ebp, esp
	
	mov esi, [ebp + 8] ; ������ ��������
	mov ecx, [ebp + 16] ; ����� ������, ������ ��������
	dec ecx
	add esi, ecx
	dec esi
	mov edi, [ebp + 12] ; ������ ��������
	std
	m_beg :
		lodsb
		mov byte ptr[edi], al
		inc edi
		loop m_beg
		cld
    
	mov ecx, [ebp + 16]
	mov esi, [ebp + 8]
	mov edi, [ebp + 12]
	repe cmpsb
	jne not_equal
	sete al
	jmp m_end
not_equal:
	xor al, al
m_end:
	mov esp, ebp
	pop ebp
	ret
_isPalindrome endp
end