#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 50

int main() {
    int i, tid;
    float a[N], b[N], c[N], d[N];

    for (i = 0; i < N; i++) {
        a[i] = i * 1.5;
        b[i] = i + 22.35;
    }

    #pragma omp parallel shared(a, b, c, d) private(i, tid)
    {
        tid = omp_get_thread_num();
        #pragma omp sections nowait
        {
            #pragma omp section
            {
                for (i = 0; i < N; i++) {
                    c[i] = a[i] + b[i];
                    printf("Thread %d: c[%d] = %f\n", tid, i, c[i]);
                }
            }
            #pragma omp section
            {
                for (i = 0; i < N; i++) {
                    d[i] = a[i] - b[i];
                    printf("Thread %d: d[%d] = %f\n", tid, i, d[i]);
                }
            }
        }
    }
    return 0;
}
