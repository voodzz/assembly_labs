#pragma once
#ifndef TASK_SUBTRACTION_H
#define TASK_SUBTRACTION_H

#include "Operation.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

template<class T>
class Subtraction : public Operation<T> {
public:
    Subtraction() = delete;

    Subtraction(const std::string& receiver, const std::string& source): receiver_(receiver), source_(source) {
        fileLogger4->set_level(spdlog::level::debug);
        fileLogger4->debug("Subtraction constructor.");
    }

    ~Subtraction() {
        fileLogger4->debug("Subtarction destructor.");
    };

    Subtraction(Subtraction&& other) = delete;
    Subtraction& operator= (Subtraction&& other) = delete;
    Subtraction(const Subtraction& other) = delete;
    Subtraction& operator= (const Subtraction& other) = delete;

    void execute() override {
        fileLogger4->info("Subtraction execution has began.");
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
            fileLogger4->critical("There is no element with key source_.");
            throw std::runtime_error("There is no element with key source_.");
        } else if (!doesSourceKeyExist) {
            fileLogger4->critical("There is no element with key receiver_.");
            throw std::runtime_error("There is no element with key receiver_.");
        }
        fileLogger4->info("Subtraction execution has ended.");
    }
private:
    std::string receiver_;
    std::string source_;
    static inline auto fileLogger4 = spdlog::basic_logger_mt("SubtractionLogger","CMakeFiles/loggers/logger1.txt");
};


#endif //TASK_SUBTRACTION_H
