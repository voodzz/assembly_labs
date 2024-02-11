#pragma once
#ifndef TASK_REPO_H
#define TASK_REPO_H

#include <map>
#include <string>
#include <vector>
#include <set>
//#include "Operation.h"

template<class T>
class Operation;

template<class T>
class Repo {
public:
    Repo() {
        data_["Ak"] = 0;
    }

    ~Repo() {
        for (auto& element : operations_) {
            delete element;
        }
    }

    std::map<std::string, T> data_;
    std::string resultKey_;
    std::vector<Operation<T>*> operations_;

    T codeExecute() {
        for (const auto& operation : operations_) {
            operation->execute();
        }
        return data_[resultKey_];
    }

    T operator[](const std::string& key) {
        return data_[key];
    }
};


#endif //TASK_REPO_H
