#include "inputs.h"

void scan_data(float* tS, float* tE, int* N)
{
    printf(" Enter range start (T0): "); scanf("%f", tS);
    printf(" Enter range end (T): "); scanf("%f", tE);
    printf(" Enter grid node count (N): "); scanf("%d", N);
}

void print_data(float tS, float tE, float delta_T, int N)
{
    printf(" --- \n");
    printf(" > Computing range: [%f, %f]\n", tS, tE);
    printf(" > Grid nodes count: %d\n", N);
    printf(" > Delta T: %f\n", delta_T);
    printf(" --- \n");
}

void output_to_file(const char* filename, int N, float* V_values, float delta_T, float tS)
{
    FILE* output_file;
    output_file = fopen(filename, "w");

    if (output_file == NULL)
    {
        printf(" Error: cannot open %s.\n");
        return;
    }

    int i;
    for (i = 0; i < N; i = i+1)
    {
        fprintf(output_file, "%f %f\n", tS + delta_T*i, V_values[i]);
    }
    fprintf(output_file, "%f %f", tS + i*delta_T, V_values[i]);
    fclose(output_file);
}