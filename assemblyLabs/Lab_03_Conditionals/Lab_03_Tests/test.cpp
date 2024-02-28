#include <map>
#include "pch.h"
#include "../task/CountEvenNumbersAndZeros.cpp"

TEST(TaskOneTest, TestName) {
	std::map<std::string, uint8_t> result = {
		{"Zero", 1},
		{"Even", 0}
	};
	std::map<std::string, uint8_t> map = countEvenNumbersAndZeros(0);
	EXPECT_EQ(map, result);
}