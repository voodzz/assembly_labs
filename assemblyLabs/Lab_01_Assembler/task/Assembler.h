#pragma once
#ifndef TASK_ASSEMBLER_H
#define TASK_ASSEMBLER_H

#include <string>
#include <fstream>
#include <map>
#include "Operation.h"
#include "Multiplication.h"
#include "Moving.h"
#include "Addition.h"
#include "Division.h"
#include "Subtraction.h"

class Assembler {
public:
    Assembler() = default;
    ~Assembler() = default;

    Assembler(Assembler&& other) = delete;
    Assembler& operator= (Assembler&& other) = delete;
    Assembler(const Assembler& other) = delete;
    Assembler& operator= (const Assembler& other) = delete;

    template<class T>
    T compileCodeFromFile(const std::string& filePath, std::map<std::string, T>& data) {
        if (data.empty()) {
            throw std::runtime_error("Data is empty.");
        }
        data["Ak"] = 0;
        std::ifstream fin(filePath, std::ios::in);
        if (!fin.is_open()) {
            throw std::runtime_error("File is not open.");
        }
        bool isDataRead = false;
        T result;
        std::string lastMove;
        while (!fin.eof()) {
            std::string str;
            std::getline(fin, str);
            if (str == "end") {
                fin.close();
                result = data[lastMove];
                return result;
            }
            if (str == ".code\r") {
                isDataRead = true;
                continue;
            }
            if (isDataRead) {
                std::string operation;
                size_t i = 0;
                while (str[i] != '\t' && str[i] != '\r') {
                    operation += str[i];
                    ++i;
                }
                ++i;

                std::string operand1;
                while (str[i] != '\t' && i < str.length() && str[i] != '\r') {
                    operand1 += str[i];
                    ++i;
                }
                ++i;

                std::string operand2;
                while (str[i] != '\t' && i < str.length() && str[i] != '\r') {
                    operand2 += str[i];
                    ++i;
                }

                if (operation == "mov") {
                    Moving<T> move;
                    move.execute(operand1, operand2, data);
                    lastMove = operand1;
                } else if (operation == "add") {
                    Addition<T> addition;
                    addition.execute(operand1, operand2, data);
                } else if (operation == "sub") {
                    Subtraction<T> subtraction;
                    subtraction.execute(operand1, operand2, data);
                } else if (operation == "mul" || operation == "imul") {
                    Multiplication<T> multiplication;
                    multiplication.execute(operand1, operand2,data);
                } else if (operation == "div" || operation == "idiv") {
                    Division<T> division;
                    division.execute(operand1, operand2, data);
                }
            }
        }
        fin.close();
        result = data[lastMove];
        return result;
    }
};


#endif //TASK_ASSEMBLER_H
