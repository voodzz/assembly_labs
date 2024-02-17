#pragma once
#ifndef DATA_READING_H
#define DATA_READING_H

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>


std::map<std::string, uint16_t> readDataFromFile(const std::string& filePath) {
	static auto fileLogger = spdlog::basic_logger_mt("DataReadingLogger", "../logger_for_task_4.txt");
	fileLogger->set_level(spdlog::level::debug);
	fileLogger->info("Data reading has began.");

	std::ifstream fin(filePath, std::ios::in);
	if (!fin.is_open()) {
		fileLogger->critical("File is not open.");
		throw std::runtime_error("File is not open.");
	}

	std::map<std::string, uint16_t> data;
	while (!fin.eof()) {
		std::string str;
		std::getline(fin, str);
		if (str == ".data") {
			continue;
		}

		if (str[0] == '\t') {
			std::string variable = str.substr(1, 2);
			std::string value;
			for (size_t i = 7; i < str.length(); ++i) {
				value += str[i];
			}

			std::stringstream converter;
			converter.str(value);
			uint16_t number;
			converter >> number;
			data[variable] = number;
		}
		else {
			std::string variable = str.substr(0, 2);
			std::string value;
			for (size_t i = 6; i < str.length(); ++i) {
				value += str[i];
			}

			std::stringstream converter;
			converter.str(value);
			uint16_t number;
			converter >> number;
			data[variable] = number;
		}
	}
	fileLogger->info("The data has been read.");
	return data;
}

#endif // !DATA_READING_H