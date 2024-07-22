#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 100000000

int main(int argc, char **argv) {
    int i, k, threads, pcount = 0;
    int *a = (int *) malloc((N + 1) * sizeof(int));
    double t1, t2;

    threads = (argc > 1) ? atoi(argv[1]) : 4;

    if (omp_get_dynamic()) omp_set_dynamic(0);
    omp_set_num_threads(threads);
    printf("%d threads max\n", omp_get_max_threads());

    for (i = 2; i <= N; i++) a[i] = 1;

    k = 2;
    t1 = omp_get_wtime();
    while (k * k <= N) {
        #pragma omp parallel for
        for (i = k * k; i <= N; i += k) a[i] = 0;

        for (i = k + 1; i <= N; i++) {
            if (a[i]) {
                k = i;
                break;
            }
        }
    }
    t2 = omp_get_wtime();
    printf("%.2f seconds\n", t2 - t1);

    for (i = 2; i <= N; i++) {
        if (a[i]) pcount++;
    }
    printf("%d primes between 0 and %d\n", pcount, N);

    free(a);
    return 0;
}
