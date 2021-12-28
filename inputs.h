#ifndef INPUTS
#define INPUTS

#include "stdio.h"
#include "stdlib.h"

void scan_data(float* tS, float* tE, int* N);

void print_data(float tS, float tE, float delta_T, int N);

void output_to_file(const char* filename, int N, float* V_values, float delta_T, float tS);

#endif//INPUTS