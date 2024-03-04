#pragma warning(disable : 4996)
#include "pow.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

int exponentiation(int number, int power) {   
    static auto fileLogger = spdlog::basic_logger_mt("Task3_Logger", "loggs/logger.txt");
    fileLogger->set_level(spdlog::level::debug);
    fileLogger->debug("Execution started.");
    int result;
    __asm {
        mov eax, number
        cmp eax, 1
        je _output
        mov ebx, number
        mov ecx, power
        cmp ecx, 0
        je _powerZero
        sub ecx, 1
        _cycle:
            imul eax, ebx
        loop _cycle
        _output:
            mov result, eax
            jmp _out
        _powerZero:
            mov result, 1
        _out:
    }
    fileLogger->debug("Execution ended.");
    return result;
}
