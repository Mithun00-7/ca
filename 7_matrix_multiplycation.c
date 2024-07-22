#include <omp.h>
#include <stdio.h>
#define NRA 62
#define NCA 15
#define NCB 7

int main() {
    int i, j, k;
    double a[NRA][NCA], b[NCA][NCB], c[NRA][NCB] = {0};

    #pragma omp parallel for collapse(2)
    for (i = 0; i < NRA; i++)
        for (j = 0; j < NCA; j++)
            a[i][j] = i + j;

    #pragma omp parallel for collapse(2)
    for (i = 0; i < NCA; i++)
        for (j = 0; j < NCB; j++)
            b[i][j] = i * j;

    #pragma omp parallel for collapse(2)
    for (i = 0; i < NRA; i++)
        for (j = 0; j < NCB; j++)
            for (k = 0; k < NCA; k++)
                c[i][j] += a[i][k] * b[k][j];

    printf("Result Matrix:\n");
    for (i = 0; i < NRA; i++) {
        for (j = 0; j < NCB; j++)
            printf("%6.2f ", c[i][j]);
        printf("\n");
    }

    return 0;
}
