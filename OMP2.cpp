    #include <iostream>
    #include <omp.h>
    #include <cstdlib>

int main() {// second task
    //
    printf("Second Task\n");
    const int n = 16000;
    int a[n], b[n];
    double start_time, end_time;

    // инициализируем массив a
    #pragma omp parallel for
    for (int i = 0; i < n; ++i)
    {
        a[i] = i;
    }

    // вычисление массива b с распределением static
        start_time = omp_get_wtime();
        #pragma omp parallel for schedule(static)
        for (int i = 1; i < n-1; i++) {
            b[i] = (a[i-1] + a[i] + a[i+1])/3.0;
        }
        end_time = omp_get_wtime();
        printf("Static time: %f\n", -(start_time-end_time));

    // вычисление массива b с распределением dynamic
        start_time = omp_get_wtime();
        #pragma omp parallel for schedule(dynamic)
        for (int i = 1; i < n-1; i++) {
            b[i] = (a[i-1] + a[i] + a[i+1])/3.0;
        }
        end_time = omp_get_wtime();
        printf("Dynamic time: %f\n", -(start_time-end_time));

    // вычисление массива b с распределением auto
        start_time = omp_get_wtime();
        #pragma omp parallel for schedule(auto)
        for (int i = 1; i < n-1; i++) {
            b[i] = (a[i-1] + a[i] + a[i+1])/3.0;
        }
        end_time = omp_get_wtime();
        printf("Auto time: %f\n", -(start_time-end_time));
     //выводим результат

    for (int i = 0; i < n; ++i)
    {

        printf("b[%d] = %d\n",i,b[i]);
    }
    printf("The winner is ...");

    return 0
}