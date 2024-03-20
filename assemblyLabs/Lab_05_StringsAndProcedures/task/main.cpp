#include <iostream>

extern "C" int __fastcall mul2(int);
 
void main() {
	std::cout << mul2(5) << '\n';
}