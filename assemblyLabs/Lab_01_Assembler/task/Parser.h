#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include "Repo.h"

class Parser {
public:
    Parser() = default;
    ~Parser() = default;

    Parser(Parser&& other) = delete;
    Parser& operator= (Parser&& other) = delete;
    Parser(const Parser& other) = delete;
    Parser& operator= (const Parser& other) = delete;

    template<class T>
    void readDataFromFile(const std::string& filePath, Repo<T>& repo) const {
        std::ifstream fin(filePath, std::ios::in);
        if (!fin.is_open()) {
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
        //return;
    }
};

#endif //PARSER_H