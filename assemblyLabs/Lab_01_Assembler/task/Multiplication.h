#pragma once
#ifndef TASK_MULTIPLICATION_H
#define TASK_MULTIPLICATION_H

#include "Operation.h"
#include "Repo.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

template<class T>
class Multiplication : public Operation<T> {
public:
    Multiplication() = delete;

    Multiplication(const std::string& receiver, const std::string& source): receiver_(receiver), source_(source) {
        fileLogger1->set_level(spdlog::level::debug);
        fileLogger1->debug("Multiplication constructor.");
    }

    ~Multiplication() {
        fileLogger1->debug("Multiplication destructor.");
    };

//    Multiplication(Multiplication&& other) = delete;
//    Multiplication& operator= (Multiplication&& other) = delete;
//    Multiplication(const Multiplication& other) = delete;
//    Multiplication& operator= (const Multiplication& other) = delete;

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

        if (!doesSourceKeyExist && doesReceiverKeyExist) {
            source_ = receiver_;
            Operation<T>::repo_->data_["Ak"] *= Operation<T>::repo_->data_[source_];
        } else if (doesSourceKeyExist && doesReceiverKeyExist) {
            Operation<T>::repo_->data_[receiver_] *= Operation<T>::repo_->data_[source_];
        } else {
            throw std::runtime_error("There is no element with key receiver_.");
        }
    }
private:
    static inline auto fileLogger1 = spdlog::basic_logger_mt("MultiplicationLogger","CMakeFiles/loggers/logger1.txt");
    std::string receiver_;
    std::string source_;
};


#endif //TASK_MULTIPLICATION_H
