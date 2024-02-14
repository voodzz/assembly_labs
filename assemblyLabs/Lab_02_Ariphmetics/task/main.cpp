#include <iostream>

int main() {
	int a, a_5, result;
	std::cout << "Input the value of a: ";
	std::cin >> a;

	__asm {
		mov ebx, a
		imul ebx, a
		imul ebx, a
		imul ebx, a
		imul ebx, a
		mov a_5, ebx
		mov ebx, a
		imul ebx, a
		imul ebx, a
		add ebx, a_5
		add ebx, a
		mov result, ebx
	}

	std::cout << "The result is: " << result;
	return 0;
}