#include <iostream>
#include "DataReading.h"
#include "Sum.h"
#include "OutputTheData.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

int main() {
	std::map<std::string, uint16_t> data = readDataFromFile("data/input_for_test11.txt");
	uint64_t result = countTheSum(data);
	print(data, result);
}