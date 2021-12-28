#ifndef CORE
#define CORE

#include "math.h"
#include "stdlib.h"
#include "stdio.h"

// Right-side function
// F(t) = sin(t) + t*cos(t)
float F(float t);

float* approximate(float tS, int N, float initial_condition, float delta_T);

#endif//CORE