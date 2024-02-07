#pragma once
#ifndef TASK_DIVISION_H
#define TASK_DIVISION_H

#include "Operation.h"

template<class T>
class Division : public Operation<T> {
public:
    Division() = default;
    ~Division() = default;

    Division(Division&& other) = delete;
    Division& operator= (Division&& other) = delete;
    Division(const Division& other) = delete;
    Division& operator= (const Division& other) = delete;

    void execute(const std::string& operand1, const std::string& operand2, std::map<std::string, T>& data) const override {
        data["Ak"] /= data[operand1];
    }
};


#endif //TASK_DIVISION_H
