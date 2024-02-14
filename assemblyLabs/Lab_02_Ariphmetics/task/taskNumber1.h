#pragma once
#ifndef TASK_NUMBER_1_H
#define TASK_NUMBER_1_H

#include <iostream>

int taskNumberOne(unsigned int a) {
	int a_5, result;

	__asm {
		mov eax, a
		mul a
		mul a
		mul a
		mul a
		mov a_5, eax
		mov eax, a
		mul a
		mul a
		add eax, a_5
		add eax, a
		mov result, eax
	}

	return result;
}

#endif TASK_NUMBER_1_H