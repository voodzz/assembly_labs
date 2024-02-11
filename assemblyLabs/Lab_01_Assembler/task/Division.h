#pragma once
#ifndef TASK_DIVISION_H
#define TASK_DIVISION_H

#include "Operation.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

template<class T>
class Division : public Operation<T> {
public:
    Division() = delete;

    Division(const std::string& source_): source_(source_) {
        fileLogger6->set_level(spdlog::level::debug);
        fileLogger6->debug("Division constructor.");
    }

    ~Division() {
        fileLogger6->debug("Division destructor.");
    }

//    Division(Division&& other) = delete;
//    Division& operator= (Division&& other) = delete;
//    Division(const Division& other) = delete;
//    Division& operator= (const Division& other) = delete;

    void execute() override {
        fileLogger6->info("Division execution has began.");
        bool doesSourceKeyExist = false;

        for (const auto& [key, element] : Operation<T>::repo_->data_) {
            if (key == source_) {
                doesSourceKeyExist = true;
            }
        }
        if (doesSourceKeyExist) {
            Operation<T>::repo_->data_["Ak"] /= Operation<T>::repo_->data_[source_];
        } else {
            fileLogger6->critical("There is no element with key source_.");
            throw std::runtime_error ("There is no element with key source_.");
        }
        fileLogger6->info("Division execution has ended.");
    }
private:
    static inline auto fileLogger6 = spdlog::basic_logger_mt("DivisionLogger","CMakeFiles/loggers/logger1.txt");
    std::string source_;
};


#endif //TASK_DIVISION_H
