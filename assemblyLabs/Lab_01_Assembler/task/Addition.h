#pragma once
#ifndef TASK_ADDITION_H
#define TASK_ADDITION_H

#include "Operation.h"

template<class T>
class Addition : public Operation<T> {
public:
    Addition() = delete;

    Addition(const std::string& receiver, const std::string& source): receiver_(receiver), source_(source) {}

    ~Addition() = default;

    Addition(Addition&& other) = delete;
    Addition& operator= (Addition&& other) = delete;
    Addition(const Addition& other) = delete;
    Addition& operator= (const Addition& other) = delete;

    void execute() override {
        bool doesReceiverKeyExist = false;
        bool doesSourceKeyExist = false;

        for (const auto& [key, element] : Operation<T>::repo_->data_) {
            if (key == receiver_) {
                doesReceiverKeyExist = true;
            }
            if (key == source_) {
                doesSourceKeyExist = true;
            }
        }

        if (doesReceiverKeyExist && doesSourceKeyExist) {
            Operation<T>::repo_->data_[receiver_] += Operation<T>::repo_->data_[source_];
        } else if (!doesReceiverKeyExist) {
            throw std::runtime_error("There is no element with key source_.");
        } else if (!doesSourceKeyExist) {
            throw std::runtime_error("There is no element with key receiver_.");
        }
    }
private:
    std::string receiver_;
    std::string source_;
};


#endif //TASK_ADDITION_H
