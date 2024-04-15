#include <iostream>

extern "C" double __cdecl intgrl();

int main() {
	double integral = intgrl();
	std::cout.precision(10);
	std::cout << integral << '\n';
}