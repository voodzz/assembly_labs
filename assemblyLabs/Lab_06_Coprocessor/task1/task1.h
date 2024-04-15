#pragma once
#ifndef TASK_1_H
#define TASK_1_H

#include <cmath>

float task1Calculate(float x, float y) {
	return (abs(x - y) * cos(x / y + y / x));
}

#endif // !TASK_1_H

