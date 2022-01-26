#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    omp_set_dynamic(0);
    omp_set_num_threads(4);
    printf("%d thread limit \n", omp_get_thread_limit());
    printf("%d thread count \n", omp_get_num_threads());
#pragma omp parallel num_threads(4)
    {

        int threadNo = omp_get_thread_num();
        printf("Hello world from %d \n", threadNo);
        printf("There are %d threads\n", omp_get_num_threads());
    }
    return 0;
}