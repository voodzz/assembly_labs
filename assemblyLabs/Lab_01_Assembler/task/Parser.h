#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

class Parser {
public:
    Parser() = default;
    ~Parser() = default;

    Parser(Parser&& other) = delete;
    Parser& operator= (Parser&& other) = delete;
    Parser(const Parser& other) = delete;
    Parser& operator= (const Parser& other) = delete;

    template<class T>
    std::map<std::string, T> readDataFromFile(const std::string& filePath) const {
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
                return data;
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
            std::stringstream converter;
            converter.str(value);
            T number;
            converter >> number;
            data[variable] = number;
        }
        fin.close();
        return data;
    }
};

#endif //PARSER_H