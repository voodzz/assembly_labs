#pragma once
#ifndef TASK_DIVISION_H
#define TASK_DIVISION_H

#include "Operation.h"

template<class T>
class Division : public Operation<T> {
public:
    Division() = delete;

    Division(const std::string& source_): source_(source_) {}

    ~Division() = default;

//    Division(Division&& other) = delete;
//    Division& operator= (Division&& other) = delete;
//    Division(const Division& other) = delete;
//    Division& operator= (const Division& other) = delete;

    void execute() override {
        bool doesSourceKeyExist = false;

        for (const auto& [key, element] : Operation<T>::repo_->data_) {
            if (key == source_) {
                doesSourceKeyExist = true;
            }
        }
        if (doesSourceKeyExist) {
            Operation<T>::repo_->data_["Ak"] /= Operation<T>::repo_->data_[source_];
        } else {
            throw std::runtime_error ("There is no element ");
        }

    }
private:
    //std::string receiver_;
    std::string source_;
};


#endif //TASK_DIVISION_H
