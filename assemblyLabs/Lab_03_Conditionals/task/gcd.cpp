#pragma warning(disable : 4996)
#include <stdexcept>
#include "gcd.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

std::pair<int, unsigned int> findGCD(std::pair<int, unsigned int> fraction) {
	static auto fileLogger = spdlog::basic_logger_mt("Task2_Logger", "loggs/logger.txt");
	fileLogger->set_level(spdlog::level::debug);
	fileLogger->debug("Execution started.");
	if (fraction.second == 0) {
		throw std::invalid_argument("Division by 0.");
	}
	int gcd;
	_asm {
		mov eax, fraction.first
		cmp eax, 0
		je _numerator
		jl _abs
		jmp _jump
		_abs:
			neg eax
		_jump:
		mov ebx, fraction.second
		_beg:
			cmp eax, ebx
			je _end // if equal
			jg _gr // if greater
			sub ebx, eax
			jmp _beg
		_gr:
			sub eax, ebx
			jmp _beg
		_end:
			mov gcd, eax // result как в eax, так и в ebx
			jmp _out
		_numerator:
			mov gcd, 1
		_out:
	}
	std::pair<int, unsigned int> result;
	result.first = fraction.first / gcd;
	result.second = fraction.second / gcd;
	fileLogger->debug("Execution ended.");
	return result;
}