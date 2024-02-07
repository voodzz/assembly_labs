#pragma once
#ifndef TASK_ADDITION_H
#define TASK_ADDITION_H

#include "Operation.h"

template<class T>
class Addition : public Operation<T> {
public:
    Addition() = default;
    ~Addition() = default;

    Addition(Addition&& other) = delete;
    Addition& operator= (Addition&& other) = delete;
    Addition(const Addition& other) = delete;
    Addition& operator= (const Addition& other) = delete;

    void execute(const std::string& operand1, const std::string& operand2, std::map<std::string, T>& data) const override {
        data[operand1] += data[operand2];
    }
};


#endif //TASK_ADDITION_H
