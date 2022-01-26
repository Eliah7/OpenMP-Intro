#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 2

// function to get matrix elements entered by the user
void getMatrixElements(int matrix[][10], int row, int column)
{

    printf("\nEnter elements: \n");

#pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < row; ++i)
    {
#pragma omp parallel for num_threads(NUM_THREADS)
        for (int j = 0; j < column; ++j)
        {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// function to multiply two matrices
void multiplyMatrices(int first[][10],
                      int second[][10],
                      int result[][10],
                      int r1, int c1, int r2, int c2)
{

    // Initializing elements of matrix mult to 0.
#pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < r1; ++i)
    {
#pragma omp parallel for num_threads(NUM_THREADS)
        for (int j = 0; j < c2; ++j)
        {
            result[i][j] = 0;
        }
    }

    // Multiplying first and second matrices and storing it in result
#pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < r1; ++i)
    {
#pragma omp parallel for num_threads(NUM_THREADS)
        for (int j = 0; j < c2; ++j)
        {
#pragma omp parallel for num_threads(NUM_THREADS)
            for (int k = 0; k < c1; ++k)
            {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

// function to display the matrix
void display(int result[][10], int row, int column)
{

    printf("\nOutput Matrix:\n");
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            printf("%d  ", result[i][j]);
            if (j == column - 1)
                printf("\n");
        }
    }
}

int main()
{
    int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2;
    printf("Enter rows and column for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and column for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Taking input until
    // 1st matrix columns is not equal to 2nd matrix row
    while (c1 != r2)
    {
        printf("Error! Enter rows and columns again.\n");
        printf("Enter rows and columns for the first matrix: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter rows and columns for the second matrix: ");
        scanf("%d%d", &r2, &c2);
    }

    // get elements of the first matrix
    getMatrixElements(first, r1, c1);

    // get elements of the second matrix
    getMatrixElements(second, r2, c2);

    // multiply two matrices.
    double start, end, time;
    start = omp_get_wtime();

    multiplyMatrices(first, second, result, r1, c1, r2, c2);
    end = omp_get_wtime();
    time = end - start;
    printf("\n\n%d thread count \n", omp_get_num_threads());
    printf("Time: %lf\n", time);
    // display the result
    display(result, r1, c2);

    return 0;
}