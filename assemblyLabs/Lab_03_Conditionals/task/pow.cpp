#include "pow.h"

int exponentiation(int number, int power) {   
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
    return result;
}
