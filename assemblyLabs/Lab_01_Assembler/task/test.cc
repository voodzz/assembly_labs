#include <gtest/gtest.h>
#include "Parser.h"
#include "Assembler.h"

TEST(ParserTest, DataReading) {
    Parser parser;
    std::map<std::string, int> result = parser.readDataFromFile<int>("CMakeFiles/data/input_for_test1.txt");
    std::map<std::string, int> tmp = {
            {"x00", -1},
            {"x01", 3},
            {"x02", 2},
            {"x03", 1},
            {"x04", 10},
            {"x05", 0},
    };
    EXPECT_EQ(result, tmp);

    result = parser.readDataFromFile<int>("CMakeFiles/data/input_for_test2.txt");
    tmp = {
            {"x00", 7},
            {"x01", 84},
            {"x02", -20},
            {"x03", 11},
            {"x04", 0},
            {"x05", 0},
    };
    EXPECT_EQ(result, tmp);

    EXPECT_ANY_THROW(result = parser.readDataFromFile<int>("chtoEtoZaFile.txt"));

    result = parser.readDataFromFile<int>("CMakeFiles/data/input_for_test3.txt");
    tmp = {};
    EXPECT_EQ(result, tmp);
}

TEST(AssemblerTest, CompilingTest) {
    Parser parser;
    std::map<std::string, int> data = parser.readDataFromFile<int>("CMakeFiles/data/input_for_test1.txt");
    Assembler assembler;
    int result;
    result = assembler.compileCodeFromFile<int>("CMakeFiles/data/input_for_test1.txt", data);
    EXPECT_EQ(result, 281);

    data = parser.readDataFromFile<int>("CMakeFiles/data/input_for_test2.txt");
    result = assembler.compileCodeFromFile<int>("CMakeFiles/data/input_for_test2.txt", data);
    EXPECT_EQ(result, 11);

    data = parser.readDataFromFile<int>("CMakeFiles/data/input_for_test3.txt");
    EXPECT_ANY_THROW(result = assembler.compileCodeFromFile<int>("CMakeFiles/data/input_for_test3.txt", data));
}