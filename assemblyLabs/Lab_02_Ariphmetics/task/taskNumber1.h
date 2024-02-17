#pragma once
#ifndef TASK_NUMBER_1_H
#define TASK_NUMBER_1_H

#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>


int taskNumberOne(unsigned int a) {
	static auto fileLogger = spdlog::basic_logger_mt ("Task1Logger", "../logger_for_tasks_1-3.txt");
	fileLogger->set_level(spdlog::level::debug);
	fileLogger->info("Task #1 execution has started.");
	
	int a_5, result;

	__asm {
		mov eax, a
		mul a
		mul a
		mul a
		mul a
		mov a_5, eax
		mov eax, a
		mul a
		mul a
		add eax, a_5
		add eax, a
		mov result, eax
	}
	fileLogger->info("The Assembly code has been executed.");
	fileLogger->info("Task #1 has been executed");
	return result;
}

#endif //TASK_NUMBER_1_H