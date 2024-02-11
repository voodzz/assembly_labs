#pragma once
#ifndef TASK_OPERATION_H
#define TASK_OPERATION_H

#include <string>
#include <map>
#include "Repo.h"

template<class T>
class Operation {
public:
    Operation() = default;
    ~Operation() = default;

//    Operation(Operation&& other) = delete;
//    Operation& operator= (Operation&& other) = delete;
//    Operation(const Operation& other) = delete;
//    Operation& operator= (const Operation& other) = delete;
    
    virtual void execute() = 0;
    static inline Repo<T>* repo_ = nullptr;
};

//template<class T>
//Repo<T>* Operation<T>::repo_ = nullptr;

#endif //TASK_OPERATION_H
