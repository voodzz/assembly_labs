#include <map>
#include "pch.h"
#include "../task/CountEvenNumbersAndZeros.h"
#include "../task/CountEvenNumbersAndZeros.cpp"
#include "../task/gcd.h"
#include "../task/gcd.cpp"
#include "../task/pow.h"
#include "../task/pow.cpp"
#include "../task/powersOfTwo.h"
#include "../task/powersOfTwo.cpp"

// TESTs FOR TASK1

std::map<std::string, uint8_t> result1 = {
		{"Zero", 0},
		{"Even", 0}
};

TEST(TaskOneTests, Zero) {
	result1["Zero"] = 1;
	result1["Even"] = 0;
	EXPECT_EQ(countEvenNumbersAndZeros(0), result1);
}

TEST(TaskOneTests, NoZerosNoEvenNumbers) {
	result1["Zero"] = 0;
	EXPECT_EQ(countEvenNumbersAndZeros(13), result1);
}

TEST(TaskOneTests, OnlyEven1) {
	result1["Even"] = 1;
	EXPECT_EQ(countEvenNumbersAndZeros(2), result1);
}

TEST(TaskOneTests, OnlyEven2) {
	result1["Even"] = 2;
	EXPECT_EQ(countEvenNumbersAndZeros(22), result1);
}

TEST(TaskOneTests, OnlyEven2ButDiff) {
	result1["Even"] = 2;
	EXPECT_EQ(countEvenNumbersAndZeros(24), result1);
}

TEST(TaskOneTests, OnlyEven3Same) {
	result1["Even"] = 3;
	EXPECT_EQ(countEvenNumbersAndZeros(222), result1);
}

TEST(TaskOneTests, NoEvenButZero) {
	result1["Even"] = 0;
	result1["Zero"] = 1;
	EXPECT_EQ(countEvenNumbersAndZeros(10), result1);
}

TEST(TaskOneTests, EvenSecond) {
	result1["Even"] = 1;
	result1["Zero"] = 0;
	EXPECT_EQ(countEvenNumbersAndZeros(1233), result1);
}

TEST(TaskOneTests, EvenThird) {
	EXPECT_EQ(countEvenNumbersAndZeros(1325), result1);
}

TEST(TaskOneTests, EvenLast) {
	result1["Even"] = 1;
	EXPECT_EQ(countEvenNumbersAndZeros(13572), result1);
}

// TESTS FOR TASK2

TEST(TaskTwoTests, ZeroNumerator) {
	EXPECT_EQ(findGCD({0,56}), std::make_pair(0,56));
}

TEST(TaskTwoTests, ZeroDenominator) {
	EXPECT_ANY_THROW(findGCD({2,0}));
}

TEST(TaskTwoTests, gcdIs1) {
	EXPECT_EQ(findGCD({1, 43}), std::make_pair(1, 43));
}

TEST(TaskTwoTests, One) {
	EXPECT_EQ(findGCD({ 1,1 }), std::make_pair(1, 1));
}

TEST(TaskTwoTests, EqualOddNumeratorDenominatorAndGCD) {
	EXPECT_EQ(findGCD({ 3,3 }), std::make_pair(1, 1));
}

TEST(TaskTwoTests, EqualEvenNumeratorDenominatorAndGCD) {
	EXPECT_EQ(findGCD({ 24,24 }), std::make_pair(1, 1));
}

TEST(TaskTwoTests, gcdNot1) {
	EXPECT_EQ(findGCD({ 24,56 }), std::make_pair(3, 7));
}

TEST(TaskTwoTests, NegativeEqual) {
	EXPECT_EQ(findGCD({ -3,3 }), std::make_pair(-1, 1));
}

TEST(TaskTwoTests, NegativeDifferent) {
	EXPECT_EQ(findGCD({ -4,64 }), std::make_pair(-1, 16));
}

TEST(TaskTwoTests, NumeratorGreaterThanDenominator) {
	EXPECT_EQ(findGCD({ 27,3 }), std::make_pair(9, 1));
}

TEST(TaskTwoTests, NegativeNumeratorGreaterThanDenominator) {
	EXPECT_EQ(findGCD({ -33,3 }), std::make_pair(-11, 1));
}

// TEST FOR TASK3

TEST(TaskThreeTests, Zero) {
	EXPECT_EQ(exponentiation(0, 20), 0);
}

TEST(TaskThreeTests, One) {
	EXPECT_EQ(exponentiation(1, 1000), 1);
}

TEST(TaskThreeTests, ZeroPower) {
	EXPECT_EQ(exponentiation(237, 0), 1);
}

TEST(TaskThreeTests, NegativeNumberEvenPower) {
	EXPECT_EQ(exponentiation(-2, 8), 256);
}

TEST(TaskThreeTests, NegativeNumberOddPower) {
	EXPECT_EQ(exponentiation(-2, 9), -512);
}

TEST(TaskThreeTests, MinusOneEvenPower) {
	EXPECT_EQ(exponentiation(-1, 10), 1);
}

TEST(TaskThreeTests, MinusOneOddPower) {
	EXPECT_EQ(exponentiation(-1, 3), -1);
}

TEST(TaskThreeTests, CommonTest1) {
	EXPECT_EQ(exponentiation(3, 3), 27);
}

TEST(TaskThreeTests, CommonTest2) {
	EXPECT_EQ(exponentiation(3, 4), 81);
}

TEST(TaskThreeTests, CommonTest3) {
	EXPECT_EQ(exponentiation(2, 4), 16);
}

TEST(TaskThreeTests, CommonTest4) {
	EXPECT_EQ(exponentiation(2, 5), 32);
}

// TEST FOR TASK4

TEST(TaskFourTests, Three) {
	EXPECT_EQ(compare(3), std::make_pair(1, 2));
}

TEST(TaskFourTests, One) {
	EXPECT_EQ(compare(1), std::make_pair(-1, 1));
}

TEST(TaskFourTests, Two) {
	EXPECT_EQ(compare(2), std::make_pair(0, 2));
}

TEST(TaskFourTests, Sixteen) {
	EXPECT_EQ(compare(16), std::make_pair(3, 5));
}

TEST(TaskFourTests, Seventeen) {
	EXPECT_EQ(compare(17), std::make_pair(4, 5));
}

TEST(TaskFourTests, sixHundered) {
	EXPECT_EQ(compare(600), std::make_pair(9, 10));
}