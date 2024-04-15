#include <iostream>

int main() {
    double a = 0.5;
    double x;
    std::cout << "Enter the power of 1/2: ";
    std::cin >> x;
    int32_t n = 1000;
    double result = 0;
    double trash;

    int factorial;
    __asm {
        finit
        loop_ :
        fldln2
            fldln2
            mov ecx, n
            dec ecx
            loopLN_ :
                fmul ST(0), ST(1)
            loop loopLN_

            mov eax, n
            mov ebx, 2
            cdq
            idiv ebx
            cmp edx, 0
            jne minus_
            jmp skip_

            minus_ :
                fchs

            skip_ :
            mov ecx, n
            dec ecx
            fld x
            fld x
            loopX_ :
                fmul ST(0), ST(1)
            loop loopX_

            fld1
            fild n
            fild n
            fsub ST(0), ST(2)
            mov ecx, n
            dec ecx
            factN_ :
                fmul ST(1), ST(0)
                fsub ST(0), ST(2)
            loop factN_
            fstp dword ptr[trash]

            fld1
            fdiv ST(0), ST(1)
            fmul ST(0), ST(3)
            fmul ST(0), ST(5)
            fadd result
            fstp qword ptr[result]
            fstp qword ptr[trash]
            fstp qword ptr[trash]
            fstp qword ptr[trash]
            fstp qword ptr[trash]
            fstp qword ptr[trash]
            fstp qword ptr[trash]
            cmp n, 2
            jne looping_
            je out_
            looping_ :
                dec n
                loop loop_
            out_ :
            fld x
            fldln2
            fchs
            fmul ST(0), ST(1)
            fld1
            fadd ST(0), ST(1)
            fadd result
            fstp qword ptr[result]
            fstp qword ptr[trash]
            fstp qword ptr[trash]
    }
    std::cout.precision(8);
    std::cout << result << '\n';
    return 0;
}
