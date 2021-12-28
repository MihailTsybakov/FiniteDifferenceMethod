#include "core.h"

// F(t) = sin(t) + t*cos(t)
float F(float t)
{
    return (sin(t) + t*cos(t));
}

float* approximate(float tS, int N, float initial_condition, float delta_T)
{
    float* V_values = (float*)malloc(sizeof(float)*(N+1));
    if (V_values == NULL)
    {
        printf(" Error: cannot allocate %d bytes.\n", N*sizeof(float));
        return NULL;
    }

    // Initial condition = u0 = u(tS)
    V_values[0] = initial_condition;
    for (int i = 1; i < N+1; i = i+1)
    {
        V_values[i] = V_values[i-1] + delta_T * F(tS + (i-1) * delta_T);
    }

    return V_values;
}