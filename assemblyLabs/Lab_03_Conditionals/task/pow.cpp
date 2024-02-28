#include "pow.h"

int exponentiation(int number, int power) {   
    int result;
    __asm {
        mov eax, number
        cmp eax, 1
        je _output
        mov ebx, number
        mov ecx, power
        sub ecx, 1
        _cycle:
            imul eax, ebx
        loop _cycle
        _output:
            mov result, eax
    }
    return result;
}
