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
#include "Repo.h"

class Assembler {
public:
    Assembler() = default;
    ~Assembler() = default;

    Assembler(Assembler&& other) = delete;
    Assembler& operator= (Assembler&& other) = delete;
    Assembler(const Assembler& other) = delete;
    Assembler& operator= (const Assembler& other) = delete;

    template<class T>
    void compileCodeFromFile(const std::string& filePath, Repo<T>& repo) {
        if (repo.data_.size() == 1) {
            throw std::runtime_error("Data is empty.");
        }
//        data["Ak"] = 0;
        std::ifstream fin(filePath, std::ios::in);
        if (!fin.is_open()) {
            throw std::runtime_error("File is not open.");
        }
        bool isDataRead = false;
        bool isCodeFound = false;
        std::string lastMove;
        while (!fin.eof()) {
            std::string str;
            std::getline(fin, str);
            if (str == "end" && !isCodeFound) {
                fin.close();
                throw std::runtime_error("There is no code.");
            } else if (str == "end") {
                fin.close();
                return;
            }
            if (str == ".code\r") {
                isDataRead = true;
                isCodeFound = true;
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
                    repo.operations_.push_back(new Moving<T>(operand1, operand2));
//                    move.execute();
//                    lastMove = operand1;
                } else if (operation == "add") {
                    repo.operations_.push_back(new Addition<T>(operand1, operand2));
//                    addition.execute();
                } else if (operation == "sub") {
                    repo.operations_.push_back(new Subtraction<T>(operand1, operand2));
//                    subtraction.execute();
                } else if (operation == "mul" || operation == "imul") {
                    repo.operations_.push_back(new Multiplication<T>(operand1, operand2));
//                    multiplication.execute();
                } else if (operation == "div" || operation == "idiv") {
                    repo.operations_.push_back(new Division<T>(operand1));
//                    division.execute();
                }
            }
        }
        fin.close();
        if (!isCodeFound) {
            throw std::runtime_error("There is no code.");
        }
    }
};


#endif //TASK_ASSEMBLER_H
