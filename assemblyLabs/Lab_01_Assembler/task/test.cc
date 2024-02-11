#include <gtest/gtest.h>
#include "File.h"
#include "Assembler.h"
#include "Operation.h"
#include "Repo.h"

TEST(ParserTests, DataReadingTest1) {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    file.readDataFromFile<int>("CMakeFiles/data/input_for_test1.txt", repo);
    std::map<std::string, int> tmp = {
            {"Ak", 0},
            {"x00", -1},
            {"x01", 3},
            {"x02", 2},
            {"x03", 1},
            {"x04", 10},
            {"x05", 0},
    };
    EXPECT_EQ(repo.data_, tmp);
}

TEST(ParserTests, DataReadingTest2) {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    file.readDataFromFile<int>("CMakeFiles/data/input_for_test2.txt", repo);
    std::map<std::string, int> tmp = {
            {"Ak", 0},
            {"x00", 7},
            {"x01", 84},
            {"x02", -20},
            {"x03", 11},
            {"x04", 0},
            {"x05", 0},
    };
    EXPECT_EQ(repo.data_, tmp);
}

TEST(ParserTests, EmptyDataTest) {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    file.readDataFromFile<int>("CMakeFiles/data/input_for_test3.txt", repo);
    std::map<std::string, int> tmp = {
            {"Ak", 0},
    };
    EXPECT_EQ(repo.data_, tmp);
}

TEST(ExecutionTests, Expression1) {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    file.readDataFromFile<int>("CMakeFiles/data/input_for_test1.txt", repo);
    Assembler assembler;
    assembler.compileCodeFromFile<int>("CMakeFiles/data/input_for_test1.txt", repo);
    EXPECT_EQ(repo.codeExecute(), 281);
    file.outputToJson("CMakeFiles/data/outputFromExpression1.json", repo);
}

TEST(ExecutionTests, Expression2) {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    file.readDataFromFile<int>("CMakeFiles/data/input_for_test2.txt", repo);
    Assembler assembler;
    assembler.compileCodeFromFile<int>("CMakeFiles/data/input_for_test2.txt", repo);
    EXPECT_EQ(repo.codeExecute(), 11);
    file.outputToJson("CMakeFiles/data/outputFromExpression2.json", repo);
}

TEST(ExecutionTests, Expression3) {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    file.readDataFromFile<int>("CMakeFiles/data/input_for_test4.txt", repo);
    Assembler assembler;
    assembler.compileCodeFromFile<int>("CMakeFiles/data/input_for_test4.txt", repo);
    EXPECT_EQ(repo.codeExecute(), 281);
    file.outputToJson("CMakeFiles/data/outputFromExpression3.json", repo);
}

TEST(ExecutionTests, Expression4) {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    file.readDataFromFile<int>("CMakeFiles/data/input_for_test5.txt", repo);
    Assembler assembler;
    assembler.compileCodeFromFile<int>("CMakeFiles/data/input_for_test5.txt", repo);
    EXPECT_EQ(repo.codeExecute(), -16);
    file.outputToJson("CMakeFiles/data/outputFromExpression4.json", repo);
}


TEST(ExceptionsTests, NoDataNoCodeTest) {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    Assembler assembler;
    file.readDataFromFile<int>("CMakeFiles/data/input_for_test3.txt", repo);
    EXPECT_ANY_THROW(
            assembler.compileCodeFromFile<int>("CMakeFiles/data/input_for_test3.txt", repo));
}

TEST(ExceptionsTests, NoCodeTest) {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    Assembler assembler;
    file.readDataFromFile<int>("CMakeFiles/data/input_for_test6.txt", repo);
    EXPECT_ANY_THROW(
            assembler.compileCodeFromFile<int>("CMakeFiles/data/input_for_test6.txt", repo));
}

TEST(ExceptionsTests, NoCodeNoEndTest) {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    Assembler assembler;
    file.readDataFromFile<int>("CMakeFiles/data/input_for_test7.txt", repo);
    EXPECT_ANY_THROW(assembler.compileCodeFromFile<int>("CMakeFiles/data/input_for_test7.txt", repo));
}