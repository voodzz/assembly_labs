#pragma once
#ifndef TASK_MULTIPLICATION_H
#define TASK_MULTIPLICATION_H

#include "Operation.h"

template<class T>
class Multiplication : public Operation<T> {
public:
    Multiplication() = default;
    ~Multiplication() = default;

    Multiplication(Multiplication&& other) = delete;
    Multiplication& operator= (Multiplication&& other) = delete;
    Multiplication(const Multiplication& other) = delete;
    Multiplication& operator= (const Multiplication& other) = delete;

    void execute(const std::string& operand1, const std::string& operand2, std::map<std::string, T>& data) const override {
        if (operand2.empty()) {
            data["Ak"] *= data[operand1];
        }
        if (!operand2.empty()) {
            data[operand1] *= data[operand2];
        }
    }
};


#endif //TASK_MULTIPLICATION_H
