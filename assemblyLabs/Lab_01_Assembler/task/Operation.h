#pragma once
#ifndef TASK_OPERATION_H
#define TASK_OPERATION_H

#include <string>
#include <map>
#include "Repo.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

template<class T>
class Operation {
public:
    Operation() {
        fileLogger5->set_level(spdlog::level::debug);
        fileLogger5->debug("Operation constructor.");
    }
    virtual ~Operation() {
        fileLogger5->debug("Operation destrcutor.");
    }

//    Operation(Operation&& other) = delete;
//    Operation& operator= (Operation&& other) = delete;
//    Operation(const Operation& other) = delete;
//    Operation& operator= (const Operation& other) = delete;
    
    virtual void execute() = 0;
    static inline Repo<T>* repo_ = nullptr;
private:
    static inline auto fileLogger5 = spdlog::basic_logger_mt("OperationLogger","CMakeFiles/loggers/logger1.txt");
};

//template<class T>
//Repo<T>* Operation<T>::repo_ = nullptr;

#endif //TASK_OPERATION_H
