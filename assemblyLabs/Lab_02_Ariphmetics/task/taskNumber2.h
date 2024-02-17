#pragma once
#ifndef TASK_NUMBER_2_H
#define TASK_NUMBER_2_H

#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

int taskNumberTwo(int a) {
	static auto fileLogger = spdlog::basic_logger_mt("Task2Logger", "../logger_for_tasks_1-3.txt");
	fileLogger->set_level(spdlog::level::debug);
	fileLogger->info("Task #2 execution has started.");
	
	if (a == 0) {
		fileLogger->critical("Division by zero will occur.");
		throw std::invalid_argument("Division by zero will occur.");
	}
	int a_5;
	int result;
	int a_3;

	__asm {
		mov eax, a
		imul eax, a
		imul eax, a
		imul eax, a
		imul eax, a
		mov a_5, eax
		mov eax, a
		imul eax, a
		sub eax, 4
		imul eax, 2
		add eax, a
		add eax, a_5
		mov ebx, a
		imul ebx, a
		imul ebx, a
		cdq
		idiv ebx
		mov result, eax
	}
	fileLogger->info("The Assembly code has been executed.");

	fileLogger->info("Task #2 has been executed");
	return result;
}

#endif //TASK_NUMBER_2_H