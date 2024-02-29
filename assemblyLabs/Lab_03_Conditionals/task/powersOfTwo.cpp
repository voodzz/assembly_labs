#include "powersOfTwo.h"

std::pair<int16_t, int16_t> compare(uint32_t a) {
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
        /*mov ebx, 2
        cdq
        idiv ebx
        cmp edx, 0
        je _zero
        jne _notZero
        _zero:
            sub cx, 2
            mov lower, cx
            jmp _out
        _notZero:
            sub cx, 1
            mov lower, cx
            jmp _out*/
        _one:
            mov lower, -1
            mov greater, 1
            jmp _out
        /*mov ebx, 2
        xor cl, cl
        _lower:
            inc cl
            imul ebx, 2
            jle _lower
        mov lower, cl*/
        _output:
            mov lower, cx
        _out:
    }
    return std::make_pair(lower, greater);
}
