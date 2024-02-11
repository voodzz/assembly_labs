#pragma once
#ifndef TASK_ADDITION_H
#define TASK_ADDITION_H

#include "Operation.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

template<class T>
class Addition : public Operation<T> {
public:
    Addition() = delete;

    Addition(const std::string& receiver, const std::string& source): receiver_(receiver), source_(source) {
        fileLogger8->set_level(spdlog::level::debug);
        fileLogger8->debug("Addition constructor.");
    }

    ~Addition() {
        fileLogger8->debug("Addition destructor.");
    }

    Addition(Addition&& other) = delete;
    Addition& operator= (Addition&& other) = delete;
    Addition(const Addition& other) = delete;
    Addition& operator= (const Addition& other) = delete;

    void execute() override {
        fileLogger8->info("Addition execution has began.");
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
            fileLogger8->critical("There is no element with key source_.");
            throw std::runtime_error("There is no element with key source_.");
        } else if (!doesSourceKeyExist) {
            fileLogger8->critical("There is no element with key receiver_.");
            throw std::runtime_error("There is no element with key receiver_.");
        }
        fileLogger8->info("Addition execution has ended.");
    }
private:
    std::string receiver_;
    std::string source_;
    static inline auto fileLogger8 = spdlog::basic_logger_mt("AdditionLogger","CMakeFiles/loggers/logger1.txt");
};


#endif //TASK_ADDITION_H
