#pragma once
#ifndef TASK_SUBTRACTION_H
#define TASK_SUBTRACTION_H

#include "Operation.h"

template<class T>
class Subtraction : public Operation<T> {
public:
    Subtraction() = delete;

    Subtraction(const std::string& receiver, const std::string& source): receiver_(receiver), source_(source) {}

    ~Subtraction() = default;

    Subtraction(Subtraction&& other) = delete;
    Subtraction& operator= (Subtraction&& other) = delete;
    Subtraction(const Subtraction& other) = delete;
    Subtraction& operator= (const Subtraction& other) = delete;

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


#endif //TASK_SUBTRACTION_H
