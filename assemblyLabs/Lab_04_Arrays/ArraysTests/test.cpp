#include "pch.h"
#include "../task/MergingArrays.h"
#include "../task/MergingArrays.cpp"
#include "../task/DifferentElements.h"
#include "../task/DifferentElements.cpp"

TEST(Task1Tests, Test1) {
	std::list<int> array = { 1, 3, 3, 3, 4 };
	std::vector<int> vec = rebuildArray(array);
	std::vector<int> result = { 3, 1, 3, 4 };
	EXPECT_EQ(vec, result);
}

TEST(Task1Tests, Test2) {
	std::list<int> array = { 1, 1, 3, 3, 4 };
	std::vector<int> vec = rebuildArray(array);
	std::vector<int> result = { 3, 1, 3, 4 };
	EXPECT_EQ(vec, result);
}

TEST(Task1Tests, Test3) {
	std::list<int> array = { 1, 1, 3, 3, 3 };
	std::vector<int> vec = rebuildArray(array);
	std::vector<int> result = { 2, 1, 3 };
	EXPECT_EQ(vec, result);
}

TEST(Task1Tests, Test4) {
	std::list<int> array = { 2, 1, 3, 3, 4 };
	std::vector<int> vec = rebuildArray(array);
	std::vector<int> result = { 4, 2, 1, 3, 4 };
	EXPECT_EQ(vec, result);
}

TEST(Task1Tests, Equal) {
	std::list<int> array = { 1, 1, 1, 1, 1 };
	std::vector<int> vec = rebuildArray(array);
	std::vector<int> result = { 1, 1 };
	EXPECT_EQ(vec, result);
}
TEST(Task2Tests, FirstGreaterThanSecond) {
	std::vector<int> result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int> arr1 = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> arr2 = { 7, 8, 9, 10 };
	EXPECT_EQ(result, mergeArrays(arr1, arr2));
}

TEST(Task2Tests, SecondGreaterThanFirst) {
	std::vector<int> result = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int> arr1 = { 1, 2, 3, 4 };
	std::vector<int> arr2 = { 5, 6, 7, 8, 9, 10 };
	EXPECT_EQ(result, mergeArrays(arr1, arr2));
}

TEST(Task2Tests, EqualSize) {
	std::vector<int> result = { 1, 2, 3, 4, 5, 6, 7,8 , 9, 10 };
	std::vector<int> arr1 = { 1, 2, 3, 4, 5 };
	std::vector<int> arr2 = { 6, 7, 8, 9, 10 };
	EXPECT_EQ(result, mergeArrays(arr1, arr2));
}

TEST(Task2Tests, NotEmptyEmpty) {
	std::vector<int> arr1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int> arr2 = {};
	EXPECT_ANY_THROW(mergeArrays(arr1, arr2));
}

TEST(Task2Tests, EmptyNotEmpty) {
	std::vector<int> arr1 = {};
	std::vector<int> arr2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	EXPECT_ANY_THROW(mergeArrays(arr1, arr2));
}

TEST(Task2Tests, EmptyEmpty) {
	std::vector<int> arr1 = {};
	std::vector<int> arr2 = {};
	EXPECT_ANY_THROW(mergeArrays(arr1, arr2));
}