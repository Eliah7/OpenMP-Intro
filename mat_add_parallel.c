#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 2

int main()
{
    omp_set_dynamic(0);
    omp_set_num_threads(NUM_THREADS);

    int r, c, a[100][100], b[100][100], sum[100][100], i, j;
    printf("Enter the number of rows (between 1 and 100): ");
    scanf("%d", &r);
    printf("Enter the number of columns (between 1 and 100): ");
    scanf("%d", &c);

    printf("\nEnter elements of 1st matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    printf("Enter elements of 2nd matrix:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
        {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }

    // adding two matrices

    double start, end, time;
    start = omp_get_wtime();
#pragma omp parallel for num_threads(NUM_THREADS)
    for (i = 0; i < r; ++i)
#pragma omp parallel for num_threads(NUM_THREADS)
        for (j = 0; j < c; ++j)
        {
            printf("\n\n%d thread count \n", omp_get_num_threads());
            sum[i][j] = a[i][j] + b[i][j];
        }
    end = omp_get_wtime();
    time = end - start;
    printf("Time: %lf\n", time);
    // printing the result
    printf("\nSum of two matrices: \n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
        {
            printf("%d   ", sum[i][j]);
            if (j == c - 1)
            {
                printf("\n\n");
            }
        }

    return 0;
}
