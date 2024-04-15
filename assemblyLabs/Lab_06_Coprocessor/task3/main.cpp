#include <iostream>

int main() {
    int n = 10000000;
    const double twelve = 12;
    const double one = 1;
    const int two = 2;
    double i = 0;
    double x = 0;
    short int trash;
    __asm {
        mov ecx, 0
        finit
        while_ :
        inc ecx
            fld i
            fadd one
            fstp qword ptr[i]
            fld i
            fld i
            fmul ST(0), ST(1)
            fld one
            fdiv ST(0), ST(1)

            mov eax, ecx
            inc eax
            cdq
            idiv two
            cmp edx, 0
            je notMinus_
            jne minus_

            notMinus_ :
                fadd x
                jmp continue_
            minus_ :
                fchs
                fadd x

            continue_ :
                fstp[x]
                fstp dword ptr[trash]
                fstp dword ptr[trash]

            cmp ecx, n
            je out_
            jne while_
        out_ :
            fld x
            fld twelve
            fmul ST(0), ST(1)
            fsqrt
            fstp qword ptr[x]
    }

    std::cout.precision(18);
    std::cout << "Approximate pi: " << x << '\n';

    return 0;
}
