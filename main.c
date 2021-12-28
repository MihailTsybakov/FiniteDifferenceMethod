#include "core.h"
#include "inputs.h"

int main()
{
    // Simple finite difference method
    // Consider equation du/dt = sin(x) + cos(x)*x

    float tS, tE, dt;
    int N;

    scan_data(&tS, &tE, &N);
    dt = (tE - tS)/N;
    print_data(tS, tE, dt, N);

    float* V;

    V = approximate(tS, N, 0, dt);
    output_to_file("FDM_1.txt", N, V, dt, tS);

    free(V);
}