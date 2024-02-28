#include <iostream>
#include <map>
#include "CountEvenNumbersAndZeros.h"
#include "gcd.h"
#include "pow.h"

int main() {
	std::map<std::string, uint8_t> result = countEvenNumbersAndZeros(102);
	std::cout << "The number of zeros: " << +result["Zero"] << '\n' << "The number of even numbers: " << +result["Even"] << '\n';
	std::cout << '\n';
	std::pair<int, unsigned int> task2 = findGCD({-24, 56});
	std::cout << "The fraction after reducing: " << task2.first << '/' << task2.second << '\n';
	std::cout << '\n';
	int task3 = exponentiation(3, 4);
	std::cout << "The result of exponentiation: " << task3;
	return 0;
}