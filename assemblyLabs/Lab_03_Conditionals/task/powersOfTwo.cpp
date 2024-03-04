#pragma warning(disable : 4996)
#include "powersOfTwo.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

std::pair<int16_t, int16_t> compare(uint32_t a) {
    static auto fileLogger = spdlog::basic_logger_mt("Task4_Logger", "loggs/logger.txt");
    fileLogger->set_level(spdlog::level::debug);
    fileLogger->debug("Execution started.");
    int16_t lower = 0;
    int16_t greater = 0;
    __asm {
        mov eax, a
        cmp eax, 1
        je _one
        mov ebx, 2
        xor cx, cx
        _greater:
            inc cx
            imul ebx, 2
            cmp ebx, eax
            jle _greater
        inc cx
        mov greater, cx
        
        xor cx, cx
        mov ebx, 2
        _while:
            cmp ebx, eax
            jge _output
            imul ebx, 2
            inc cx
            jmp _while
        _one:
            mov lower, -1
            mov greater, 1
            jmp _out
        _output:
            mov lower, cx
        _out:
    }
    fileLogger->debug("Execution ended.");
    return std::make_pair(lower, greater);
}
