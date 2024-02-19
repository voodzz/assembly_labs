#pragma once
#ifndef OUTPUT_THE_DATA_H
#define OUTPUT_THE_DATA_H

#include <iostream>
#include <map>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

void print(std::map<std::string, uint16_t>& data, uint64_t& result) {
	static auto fileLogger = spdlog::basic_logger_mt("OutputLogger", "../logger_for_task_4.txt");
	fileLogger->set_level(spdlog::level::debug);
	if (data["C4"] == 0) {
		std::cout << "The result is : " << result << " or " << std::hex << data["C3"] << ':' << data["C2"] << ':' << data["C1"] << std::endl;
	} else {
		std::cout << "The result is : " << result << " or " << std::hex << data["C4"] << ':' << data["C3"] << ':' << data["C2"] << ':' << data["C1"] << std::endl;
	}
	fileLogger->info("The result has been printed.");
}

#endif // !OUTPUT_THE_DATA_H
