#pragma once
#ifndef TASK_MOVING_H
#define TASK_MOVING_H

#include "Operation.h"

template<class T>
class Moving : public Operation<T> {
public:
    Moving() = default;
    ~Moving() = default;

    Moving(Moving&& other) = delete;
    Moving& operator= (Moving&& other) = delete;
    Moving(const Moving& other) = delete;
    Moving& operator= (const Moving& other) = delete;

    void execute(const std::string& operand1, const std::string& operand2, std::map<std::string, T>& data) const override {
            data[operand1] = data[operand2];
    }
};


#endif //TASK_MOVING_H
