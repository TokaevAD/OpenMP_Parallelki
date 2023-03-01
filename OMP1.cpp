#include <iostream>
#include <omp.h>
#include <cstdlib>

int main() {
    // first task
    //
    printf("First Task\n");
    #pragma omp parallel num_threads(8)
    {
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();

        printf("Thread %d of %d Says: Hello World!\n",id, numThreads);
    }

    return 0
}