#pragma once
#ifndef TASK_REPO_H
#define TASK_REPO_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

template<class T>
class Operation;

template<class T>
class Repo {
public:
    Repo() {
        data_["Ak"] = 0;
        fileLogger3->set_level(spdlog::level::debug);
        fileLogger3->debug("Repo constructor.");
    }

    ~Repo() {
        for (auto& element : operations_) {
            delete element;
        }
        fileLogger3->debug("Repo destructor.");
    }

    std::map<std::string, T> data_;
    std::string resultKey_;
    std::vector<Operation<T>*> operations_;

    T codeExecute() {
        fileLogger3->info("Code execution has started.");
        for (const auto& operation : operations_) {
            operation->execute();
        }
        fileLogger3->info("Code execution has ended.");
        return data_[resultKey_];
    }

    T operator[](const std::string& key) {
        return data_[key];
    }
private:
    static inline auto fileLogger3 = spdlog::basic_logger_mt("RepoLogger","CMakeFiles/loggers/logger1.txt");
};


#endif //TASK_REPO_H
