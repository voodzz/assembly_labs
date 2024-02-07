#pragma once
#ifndef TASK_OPERATION_H
#define TASK_OPERATION_H

#include <string>
#include <map>

template<class T>
class Operation {
public:
    Operation() = default;
    ~Operation() = default;

    Operation(Operation&& other) = delete;
    Operation& operator= (Operation&& other) = delete;
    Operation(const Operation& other) = delete;
    Operation& operator= (const Operation& other) = delete;
    
    virtual void execute(const std::string& operand1, const std::string& operand2, std::map<std::string, T>& data) const = 0;
};


#endif //TASK_OPERATION_H
