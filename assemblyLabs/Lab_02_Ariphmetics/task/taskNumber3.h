#pragma once
#ifndef TASK_NUMBER_3_H
#define TASK_NUMBER_3_H

#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

int taskNumberThree(int32_t a) {
	static auto fileLogger = spdlog::basic_logger_mt("Task3Logger", "../logger_for_tasks_1-3.txt");
	fileLogger->set_level(spdlog::level::debug);
	fileLogger->info("Task #3 execution has started.");
	
	if (a == 1) {
		fileLogger->critical("a equals 1.");
		throw std::invalid_argument("a can not be 1.");
	}
	int n;
	int counter = 0;
	__asm {
		mov eax, a
		mov ecx, counter
		cycle: 
		inc ecx
		imul eax, a
		jno cycle
		mov n, ecx
	}
	fileLogger->info("The Assembly code has been executed.");

	fileLogger->info("Task #2 has been executed");
	return n;
}

#endif //TASK_NUMBER_2_H