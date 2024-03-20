#include <stdexcept>
#include "MergingArrays.h"

std::vector<int> mergeArrays(std::vector<int>& arr1, std::vector<int>& arr2) {
	if (arr1.empty() || arr2.empty()) {
		throw std::invalid_argument("Arrays must not be empty.");
	}
	int* ptrNew = new int[arr1.size() + arr2.size()];
	std::copy(arr1.begin(), arr1.end(), ptrNew);

	ptrNew += arr1.size() - 1;

	int* ptr2 = arr2.data() - 1;
	int size_ = arr1.size() + arr2.size();
	int size2 = arr2.size();

	__asm {
		mov eax, ptrNew
		mov ebx, ptr2
		mov ecx, size2
		_loop :
			add eax, 4
			add ebx, 4
			mov edx, [ebx]
			mov[eax], edx
			loop _loop
			mov ecx, size_
			sub ecx, 1
		_front:
			sub eax, 4
			loop _front
			mov ptrNew, eax
	}
	
	std::vector<int> result;
	for (size_t i = 0; i != size_; ++i) {
		result.push_back(ptrNew[i]);
	}
	
	return result;
}
