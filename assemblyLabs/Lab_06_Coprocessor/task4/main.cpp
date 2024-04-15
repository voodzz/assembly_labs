#include <iostream>

extern "C" double __cdecl ln2(int32_t k);

int main() {
	int32_t k = 2'147'483'647;
	double log2 = ln2(k);

	std::cout.precision(11);
	std::cout << "ln2 = " << log2 << '\n';
	return 0;
}