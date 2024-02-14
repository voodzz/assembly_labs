#pragma once
#ifndef TASK_NUMBER_2_H
#define TASK_NUMBER_2_H

#include <iostream>

int taskNumberTwo(int a) {
	int a_5;
	int result;
	int a_3;

	__asm {
		mov eax, a
		imul eax, a
		imul eax, a
		imul eax, a
		imul eax, a
		mov a_5, eax
		mov eax, a
		imul eax, a
		sub eax, 4
		imul eax, 2
		add eax, a
		add eax, a_5
		mov ebx, a
		imul ebx, a
		imul ebx, a
		cdq
		idiv ebx
		mov result, eax
	}

	return result;
}

#endif TASK_NUMBER_2_H