#include <omp.h>
#include <stdio.h>

int a, b;
float x;
#pragma omp threadprivate(a, x)

int main() {
    omp_set_dynamic(0);

    #pragma omp parallel private(b)
    {
        int tid = omp_get_thread_num();
        a = tid;
        b = tid;
        x = 1.1 * tid + 1.0;
        printf("Thread %d: a = %d, b = %d, x = %f\n", tid, a, b, x);
    }

    printf("************************************\n");
    printf("Master thread doing serial work here\n");
    printf("************************************\n");

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("Thread %d: a = %d, b = %d, x = %f\n", tid, a, b, x);
    }

    return 0;
}
