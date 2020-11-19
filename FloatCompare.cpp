/*
 * FloatCompare.cpp
 *
 */

#include "FloatCompare.h"

/**
 * The two values are approximately equal
 *
 * @param a left hand value
 * @param b right hand value
 * @param epsilon  the difference between 1.0 and the next value representable by the floating-point
 * @return true is approximately equal
 */
bool approximatelyEqual(float a, float b, float epsilon) {
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

/**
 * The two values are essentially equal
 *
 * @param a left hand value
 * @param b right hand value
 * @param epsilon  the difference between 1.0 and the next value representable by the floating-point
 * @return true is essentially equal
 */
bool essentiallyEqual(float a, float b, float epsilon) {
	return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

/**
 * The one value definitely greater than the other
 *
 * @param a left hand value
 * @param b right hand value
 * @param epsilon  the difference between 1.0 and the next value representable by the floating-point
 * @return true is definitely greater than
 */
bool definitelyGreaterThan(float a, float b, float epsilon) {
	return (a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

/**
 * The one value definitely less than the other
 *
 * @param a left hand value
 * @param b right hand value
 * @param epsilon  the difference between 1.0 and the next value representable by the floating-point
 * @return true is definitely less than
 */
bool definitelyLessThan(float a, float b, float epsilon) {
	return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
