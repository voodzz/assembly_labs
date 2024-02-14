#include "pch.h"
#include "../task/taskNumber1.h"
#include "../task/taskNumber2.h"
#include "../task/taskNumber3.h"

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