#pragma once
#ifndef SUM_H
#define SUM_H

#include <iostream>
#include <map>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

uint64_t countTheSum(std::map<std::string, uint16_t>& data) {
	static auto fileLogger = spdlog::basic_logger_mt("CountingLogger", "../logger_for_task_4.txt");
	fileLogger->set_level(spdlog::level::debug);
	fileLogger->info("The counting has began.");
	uint16_t A1 = data["A1"];
	uint16_t A2 = data["A2"];
	uint16_t A3 = data["A3"];
	uint16_t B1 = data["B1"];
	uint16_t B2 = data["B2"];
	uint16_t B3 = data["B3"];
	uint16_t C1 = data["C1"];
	uint16_t C2 = data["C2"];
	uint16_t C3 = data["C3"];

	__asm {
		mov ax, A1
		mov bx, A2
		mov dx, A3
		add ax, B1		
		adc bx, B2
		adc dx, B3
		mov C1, ax
		mov C2, bx
		mov C3, dx
	}
	fileLogger->info("The Assembly code has been executed.");

	data["C1"] = C1;
	data["C2"] = C2;
	data["C3"] = C3;

	uint64_t c3 = static_cast<uint64_t>(C3);
	c3 <<= 32;
	uint64_t c2 = static_cast<uint64_t>(C2);
	c2 <<= 16;
	uint64_t c1 = static_cast<uint64_t>(C1);
	uint64_t result = c3 + c2 + c1;
	
	fileLogger->info("Counting has ended successfully.");
	return result;
}

#endif // !SUM_H
