#include <omp.h>
#include <stdio.h>

int main() {
    int i;
    float a[1000], b[1000], sum = 0.0;

    for (i = 0; i < 1000; i++) {
        a[i] = b[i] = i * 1.0;
    }

    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < 1000; i++) {
        sum += a[i] * b[i];
    }

    printf("Sum = %f\n", sum);
    return 0;
}
