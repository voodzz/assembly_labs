#include <iostream>
#include "taskNumber3.h"

int main() {
	int a;
	std::cout << "Input the value of a: ";
	std::cin >> a;
	int n = taskNumberThree(a);
	std::cout << "The value of n: " << n << '\n';
	return 0;
}