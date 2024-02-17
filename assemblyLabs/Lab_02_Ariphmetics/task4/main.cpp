#include <iostream>
#include "DataReading.h"
#include "Sum.h"
#include "OutputTheData.h"

int main() {
	std::map<std::string, uint16_t> data = readDataFromFile("data/input.txt");
	uint64_t result = countTheSum(data);
	print(data, result);
}