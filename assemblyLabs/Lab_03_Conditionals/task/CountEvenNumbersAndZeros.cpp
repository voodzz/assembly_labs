#pragma warning(disable : 4996)
#include "CountEvenNumbersAndZeros.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

std::map<std::string, uint8_t> countEvenNumbersAndZeros(int a) {
	static auto fileLogger = spdlog::basic_logger_mt("Task1_Logger", "loggs/logger.txt");
	fileLogger->set_level(spdlog::level::debug);
	fileLogger->debug("Execution started.");
	std::map<std::string, uint8_t> result = {
		{"Zero", 0},
		{"Even", 0}
	};
	uint8_t evenCounter = 0; // ch
	uint8_t zeroCounter = 0; // cl
	__asm {
		xor cl, cl
		xor ch, ch
		xor al, al
		mov ebx, 10
		mov eax, a
		cmp a, 0 // is a positive or negative
		je _zero
		jl _abs
		jmp _loop
		_abs: 
			neg a
		_loop:
			cmp eax, 0
			je _output
			cdq
			idiv ebx	// allocation of the last digit
			test edx, 1 // 0b00000001
			jnz _loop // ignoring odd number
			cmp edx, 0
			je _zero
			jmp _even
		_zero:
			inc cl
			cmp eax, 0
			je _output
			jmp _loop
		_even:
			inc ch
			cmp eax, 0
			je _output
			jmp _loop
		_output:
			mov evenCounter, ch
			mov zeroCounter, cl
	}
	result["Zero"] = zeroCounter;
	result["Even"] = evenCounter;
	fileLogger->debug("Execution ended.");
	return result;
}