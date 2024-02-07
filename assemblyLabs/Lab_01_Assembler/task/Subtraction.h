#pragma once
#ifndef TASK_SUBTRACTION_H
#define TASK_SUBTRACTION_H

#include "Operation.h"

template<class T>
class Subtraction : public Operation<T> {
public:
    Subtraction() = default;
    ~Subtraction() = default;

    Subtraction(Subtraction&& other) = delete;
    Subtraction& operator= (Subtraction&& other) = delete;
    Subtraction(const Subtraction& other) = delete;
    Subtraction& operator= (const Subtraction& other) = delete;

    void execute(const std::string& operand1, const std::string& operand2, std::map<std::string, T>& data) const override {
        data[operand1] -= data[operand2];
    }
};


#endif //TASK_SUBTRACTION_H
