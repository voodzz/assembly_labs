#pragma once
#ifndef TASK_MOVING_H
#define TASK_MOVING_H

#include "Operation.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

template<class T>
class Moving : public Operation<T> {
public:
    Moving() = delete;
    ~Moving() {
        fileLogger9->debug("Moving destructor.");
    }

    Moving(const std::string& receiver, const std::string& source) : receiver_(receiver), source_(source) {
        fileLogger9->set_level(spdlog::level::debug);
        fileLogger9->debug("Moving constructor.");
    }

//    Moving(Moving&& other) = delete;
//    Moving& operator= (Moving&& other) = delete;
//    Moving(const Moving& other) = delete;
//    Moving& operator= (const Moving& other) = delete;

    void execute() override {
        fileLogger9->info("Moving execution has began.");
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
            Operation<T>::repo_->data_[receiver_] = Operation<T>::repo_->data_[source_];
        } else if (!doesReceiverKeyExist) {
            fileLogger9->critical("There is no element with key source_.");
            throw std::runtime_error("There is no element with key source_.");
        } else if (!doesSourceKeyExist) {
            fileLogger9->critical("There is no element with key receiver_.");
            throw std::runtime_error("There is no element with key receiver_.");
        }
        fileLogger9->info("Division execution has ended.");
    }
private:
    std::string receiver_;
    std::string source_;
    static inline auto fileLogger9 = spdlog::basic_logger_mt("MovingLogger","CMakeFiles/loggers/logger1.txt");
};


#endif //TASK_MOVING_H
