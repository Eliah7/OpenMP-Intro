#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
#pragma omp parallel
    {
        omp_set_num_threads(4);
        int threadNo = omp_get_thread_num();
        printf("Hello world from %d \n", threadNo);
        printf("There are %d threads", omp_get_num_threads());
    }
    return 0;
}