#include "CountEvenNumbersAndZeros.h"

std::map<std::string, uint8_t> countEvenNumbersAndZeros(int a) {
	std::map<std::string, uint8_t> result = {
		{"Zero", 0},
		{"Even", 0}
	};
	uint8_t evenCounter = 0; // ch
	uint8_t zeroCounter = 0; // cl
	__asm {
		xor cl, cl
		xor ch, ch
		mov eax, a
		cmp a, 0 // is a positive or negative
		jl _abs
		jmp _loop
		_abs: 
			neg a
		_loop:
			cdq
			idiv 10	// allocation of the last digit
			test edx, 1 // 0b00000001
			jnz _loop // ignoring odd number
			inc ch

	}
}