#include "pch.h"
#include "../task/taskNumber1.h"
#include "../task/taskNumber2.h"
#include "../task/taskNumber3.h"
#include "../task4/DataReading.h"
#include "../task4/Sum.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

TEST(TaskOneTests, Tests) {
  EXPECT_EQ(taskNumberOne(1), 3);
  EXPECT_EQ(taskNumberOne(2), 42);
  EXPECT_EQ(taskNumberOne(3), 273);
  EXPECT_EQ(taskNumberOne(4), 1092);
  EXPECT_EQ(taskNumberOne(5), 3255);
}

TEST(TaskTwoTests, Tests) {
	EXPECT_EQ(taskNumberTwo(1), -4);
	EXPECT_EQ(taskNumberTwo(2), 4);
	EXPECT_EQ(taskNumberTwo(3), 9);
	EXPECT_EQ(taskNumberTwo(4), 16);
	EXPECT_EQ(taskNumberTwo(5), 25);
	EXPECT_ANY_THROW(taskNumberTwo(0));
}

TEST(TaskThreeTests, Tests) {
	EXPECT_ANY_THROW(taskNumberThree(1));
	EXPECT_EQ(taskNumberThree(2), 30);
	EXPECT_EQ(taskNumberThree(3), 19);
	EXPECT_EQ(taskNumberThree(4), 15);
	EXPECT_EQ(taskNumberThree(5), 13);
	EXPECT_EQ(taskNumberThree(6), 11);
	EXPECT_EQ(taskNumberThree(7), 11);
	EXPECT_EQ(taskNumberThree(8), 10);
	EXPECT_EQ(taskNumberThree(9), 9);
	EXPECT_EQ(taskNumberThree(10), 9);
}

TEST(DataReadingTests, WithTab) {
	std::map<std::string, uint16_t> result = {
		{"A1", 4},
		{"A2", 2},
		{"A3", 1},
		{"B1", 7},
		{"B2", 19},
		{"B3", 85},
		{"C1", 0},
		{"C2", 0},
		{"C3", 0}
	};
	EXPECT_EQ(readDataFromFile("../task4/data/input_for_test1.txt"), result);
}

TEST(DataReadingTests, WithoutTab) {
	std::map<std::string, uint16_t> result = {
		{"A1", 5},
		{"A2", 23},
		{"A3", 11},
		{"B1", 67},
		{"B2", 30},
		{"B3", 578},
		{"C1", 0},
		{"C2", 2},
		{"C3", 0}
	};
	EXPECT_EQ(readDataFromFile("../task4/data/input_for_test2.txt"), result);
}

TEST(DataReadingTests, Exceptions) {
	EXPECT_ANY_THROW(readDataFromFile("file.txt"));
	EXPECT_ANY_THROW(readDataFromFile("oooga booga"));
}

TEST(CountingTest, Test1) {
	std::map<std::string, uint16_t> data = readDataFromFile("../task4/data/input_for_test3.txt");
	EXPECT_EQ(countTheSum(data), 60130590738);
}

TEST(CountingTest, Test2) {
	std::map<std::string, uint16_t> data = readDataFromFile("../task4/data/input_for_test4.txt");
	EXPECT_EQ(countTheSum(data), 8590262270);
}

TEST(CountingTest, Test3) {
	std::map<std::string, uint16_t> data = readDataFromFile("../task4/data/input_for_test5.txt");
	EXPECT_EQ(countTheSum(data), 65536);
}

TEST(CountingTest, Test4) {
	std::map<std::string, uint16_t> data = readDataFromFile("../task4/data/input_for_test6.txt");
	EXPECT_EQ(countTheSum(data), 12890439680);
}