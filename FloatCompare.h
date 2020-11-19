/*
 * FloatCompare.h
 *
 *  Created on: Jan 4, 2020
 *      Author: student
 */

#ifndef FLOATCOMPARE_H_
#define FLOATCOMPARE_H_

#include <cmath>
#include <algorithm>

bool approximatelyEqual(float a, float b, float epsilon = 0.01);

bool essentiallyEqual(float a, float b, float epsilon = 0.01);

bool definitelyGreaterThan(float a, float b, float epsilon = 0.01);

bool definitelyLessThan(float a, float b, float epsilon = 0.01);

#endif /* FLOATCOMPARE_H_ */