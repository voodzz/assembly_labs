#include <iostream>
#include "task1.h"

extern "C" float __cdecl calculateTask1(float, float);

int main() {
	float x = 5.1;
	int y = 2.0;
	float z = calculateTask1(x, y);
	std::cout << z << '\n';
	return 0;
}