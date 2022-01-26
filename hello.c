#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

    omp_set_dynamic(0);
    omp_set_num_threads(4);

    double start, end, time;
    start = omp_get_wtime();
#pragma omp parallel num_threads(4)
    {
        printf("Hello world! I'm thread %d out of %d threads.\n",
               omp_get_thread_num(), omp_get_num_threads());
    }
    end = omp_get_wtime();
    time = end - start;
    printf("Time: %lf\n", time);
    return 0;
}