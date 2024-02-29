#include <iostream>
#include <map>
#include "CountEvenNumbersAndZeros.h"
#include "gcd.h"
#include "pow.h"
#include "powersOfTwo.h"

int main() {
	std::map<std::string, uint8_t> result = countEvenNumbersAndZeros(102);
	std::cout << "The number of zeros: " << +result["Zero"] << '\n' << "The number of even numbers: " << +result["Even"] << '\n';
	std::cout << '\n';
	std::pair<int, unsigned int> task2 = findGCD({-24, 56});
	std::cout << "The fraction after reducing: " << task2.first << '/' << task2.second << '\n';
	std::cout << '\n';
	int task3 = exponentiation(3, 0);
	std::cout << "The result of exponentiation: " << task3 << '\n' << '\n';
	std::pair<int16_t, int16_t> pair = compare(16);
	std::cout << "The number is between these powers of 2: " << +pair.first << " and " << +pair.second << '\n';
	return 0;
}