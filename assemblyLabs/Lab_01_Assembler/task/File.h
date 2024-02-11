#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include "Repo.h"
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

class File {
public:
    File() {
        fileLogger2->set_level(spdlog::level::debug);
        fileLogger2->debug("File constructor.");
    }
    ~File() {
        fileLogger2->debug("File destructor.");
    }

    File(File&& other) = delete;
    File& operator= (File&& other) = delete;
    File(const File& other) = delete;
    File& operator= (const File& other) = delete;

    template<class T>
    void readDataFromFile(const std::string& filePath, Repo<T>& repo) const {
        fileLogger2->info("Reading from file has began.");
        std::ifstream fin(filePath, std::ios::in);
        if (!fin.is_open()) {
            fileLogger2->critical("File is not open.");
            throw std::runtime_error("File is not open.");
        }
        std::map<std::string, T> data;
        while (!fin.eof()) {
            std::string str;
            std::getline(fin, str);
            if (str == ".data\r") {
                continue;
            }

            if (str == ".code\r") {
                fin.close();
                //return;
                break;
            }

            std::string variable;
            size_t i = 0;
            while (str[i] != '\t') {
                variable += str[i];
                ++i;
            }
            ++i;
            std::string value;
            while (str[i] != '\t' && i != str.length()) {
                value += str[i];
                ++i;
            }
            if (value == "?") {
                repo.resultKey_ = variable;
            }
            std::stringstream converter;
            converter.str(value);
            T number;
            converter >> number;
            repo.data_[variable] = number;
        }
        fin.close();
        fileLogger2->info("Reading has been finished.");
    }

    template<class T>
    void outputToJson(const std::string& filePath, Repo<T>& repo) {
        fileLogger2->info("Writing to the output file has began.");
        T number = repo.data_[repo.resultKey_];
        nlohmann::json result;
        result["Result"] = repo.data_[repo.resultKey_];
        std::ofstream fout(filePath, std::ios::out);
        if (!fout.is_open()) {
            fileLogger2->critical("File is not open.");
            throw std::runtime_error("The file is not open.");
        }
        fout << result << std::endl;
        fileLogger2->info("Writing has been finished.");
        fout.close();
    }
private:
    static inline auto fileLogger2 = spdlog::basic_logger_mt("FileLogger","CMakeFiles/loggers/logger1.txt");
};

#endif //PARSER_H