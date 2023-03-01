#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 1000; // размер матриц

void generateMatrix(int **matrix) {
    //srand(time(nullptr));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void sequential_multiply(double **A, double **B, double **C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void parallel_multiply(double **A, double **B, double **C, int num_threads) {
    omp_set_num_threads(num_threads);
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
double start_time, end_time;

printf("Fourth task\n");
    double **A, **B, **C;
    A = new double*[N];
    B = new double*[N];
    C = new double*[N];

    for (int i = 0; i < N; i++) {
        A[i] = new double[N];
        B[i] = new double[N];
        C[i] = new double[N];
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }



    // sequential multiply
    start_time = omp_get_wtime();
    sequential_multiply(A, B, C);
    end_time = omp_get_wtime();

    printf("Sequential execution time: %f s\n", end_time - start_time);
    // parallel multiply with 2 threads
    start_time = omp_get_wtime();
    parallel_multiply(A, B, C, 2);
    end_time = omp_get_wtime();

    printf("Parallel execution time with 2 threads: %f s\n", end_time - start_time);

    // parallel multiply with 4 threads
    start_time = omp_get_wtime();
    parallel_multiply(A, B, C, 4);
    end_time = omp_get_wtime();
    printf("Parallel execution time with 4 threads: %f s\n", end_time - start_time);

    // parallel multiply with 8 threads
    start_time = omp_get_wtime();
    parallel_multiply(A, B, C, 8);
    end_time = omp_get_wtime();
    printf("Parallel execution time with 8 threads: %f s\n", end_time - start_time);

    // free memory
    for (int i = 0; i < N; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

