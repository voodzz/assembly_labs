#include <algorithm>
#include <iterator>
#include <iostream>
#include "DifferenceAndIntersection.h"

std::map<std::string, bool> isDifferenceIsIntersection(std::vector<int>& examine, std::vector<int>& arr1, std::vector<int>& arr2) {
	std::map<std::string, bool> result = {
		{"Difference", 0},
		{"Intersection", 0}
	};
	
	int* ptr1 = arr1.data() - 1;
	int size1 = arr1.size();
	int* ptr2 = arr2.data() - 1;
	int size2 = arr2.size();
	int numberOfDeletes = 0;
	/*__asm {
		mov ebx, ptr2
		mov edx, 0
		_array2:
			mov eax, ptr1
			mov ecx, size1
			cmp edx, size2
			je _out
			add ebx, 4
			mov esi, dword ptr[ebx]
		_comparing:
			add eax, 4
			cmp dword ptr [eax], esi
			je _delete
			loop _comparing
			inc edx
			jmp _array2
		_delete:
			mov edi, eax
			add edi, 4
			mov ebp, dword ptr [edi]
			mov dword ptr [eax], ebp
			add eax, 4
			jmp _array2
		_out:
			add eax, 4
			mov ptr1, eax
			mov eax, numberOfDeletes
			sub size1, eax
	}*/
	
	__asm {
		mov ebx, [ptr2]
		mov edx, 0
		_array2:
			mov eax, [ptr1]
			mov ecx, [size1]
			cmp edx, [size2]
			je _out
			add ebx, 4
			mov esi, [bx]
		_comparing:
			add eax, 4
			xchg eax, ebx
			cmp [ebx], esi
			xchg eax, ebx
			je _delete
			loop _comparing
			inc edx
			jmp _array2
		_delete :
			inc edx
			inc [numberOfDeletes]
			dec ecx
			jz _array2
			mov edi, eax
			add edi, 4
			mov ebp, [edi]
			xchg eax, ebx
			mov [ebx], ebp
			xchg eax, ebx
			add eax, 4
			loop _delete
			jmp _array2
		_out :
			add eax, 4
			mov[ptr1], eax
			mov eax, [numberOfDeletes]
			sub[size1], eax
	}
	for (size_t i = 0; i != size1; ++i) {
		std::cout << ptr1[i] << ' ';
	}

	std::cout << '\n' << '\n';

	return result;
}
