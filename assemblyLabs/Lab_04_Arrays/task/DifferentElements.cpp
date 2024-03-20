#include "DifferentElements.h"
#include <list>
#include <vector>

std::vector<int> rebuildArray(std::list<int>& array) {
	array.push_front(array.size());

	std::vector<int> list;
	for (auto element : array) {
		list.push_back(element);
	}
	
	int* ptrArr = list.data();
	int _size = list[0];
	int* ptrEnd = &list.back();
	int firstElement = ptrArr[1];

	__asm {
		mov esi, ptrArr // array here
		add esi, 4
		mov edi, [esi] // first element
		sub esi, 4
		mov ebx, ptrEnd // end of the array
		_comparing :
			mov ecx, _size
			dec ecx
			mov eax, esi
			add eax, 4
			cmp esi, ebx
			je _out
			add esi, 4
			mov edx, [esi] // number to compare with
			_loop:
				cmp eax, ebx
				je _comparing
				add eax, 4
				cmp [eax], edi
				je _skip
				cmp[eax], edx
				je _replace
				loop _loop
				jmp _comparing
		_skip:
			loop _loop
		_replace :
			mov[eax], edi
			dec ecx
			jmp _loop
		_out :
	}

	int counter = 0;
	__asm {
		mov eax, ptrArr
		mov ecx, _size
		_counting:
			add eax, 4
			cmp [eax], edi
			je _increase
			loop _counting
			jmp _out3
		_increase:
			inc counter
			loop _counting
		_out3:
	}

	int newSize = _size - counter + 1;
	int* result = new int[newSize + 1];

	_asm {
		mov eax, result // the beginning of the result
		mov esi, ptrArr // old array
		mov ecx, newSize
		mov[eax], ecx // first element of result is new size
		add eax, 4
		mov ebx, [esi + 4]
		mov[eax], ebx
		xor ebx, ebx
		xor ecx, ecx
		mov ecx, _size
		_loop2 :
			add esi, 4
			mov ebx, [esi]
			cmp ebx, firstElement
			je _continue
			jne _addition
			jmp _out2
		_continue :
			loop _loop2
			jmp _out2
		_addition :
			add eax, 4
			mov[eax], ebx
			loop _loop2
			jmp _out2
		_out2 :
	}
	
	std::vector<int> result_vec;
	for (size_t i = 0; i != newSize + 1; ++i) {
		result_vec.push_back(result[i]);
	}

	return result_vec;
}
