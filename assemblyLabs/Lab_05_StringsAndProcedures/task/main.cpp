#include <iostream>
#include <algorithm>

extern "C" bool __cdecl isPalindrome(char*, char*, int);
 
int main() {
	char s1[6] = "madam";
	char s2[6] = { 0 };
	bool result = isPalindrome(s1, s2, 6);
	std::cout.setf(std::ios::boolalpha);
	std::cout << result << '\n';
	return 0;
}