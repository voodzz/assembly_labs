#pragma once
#ifndef TASK_NUMBER_3_H
#define TASK_NUMBER_3_H

#include <iostream>

int taskNumberThree(int32_t a) {
	if (a == 1) {
		throw std::invalid_argument("a can not be 1.");
	}
	int n;
	int counter = 0;
	__asm {
		mov eax, a
		mov ecx, counter
		cycle: 
		inc ecx
		imul eax, a
		jno cycle
		mov n, ecx
	}
	return n;
}

#endif TASK_NUMBER_2_H