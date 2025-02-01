#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void x86(size_t n, int64_t* z, int64_t* x, int64_t* y);

int64_t dotProduct(int64_t  arrA[], int64_t  arrB[], size_t  arrSize) {
    int64_t sum = 0;

    for (size_t i = 0; i < arrSize; i++) {
        sum += arrA[i] * arrB[i];
    }

    return sum;
}

int main() {
    const size_t ARRAY_SIZE = 1 << 24;
    const size_t ARRAY_BYTES = ARRAY_SIZE * sizeof(int64_t);
    printf("Number of elements = %zu\n", ARRAY_SIZE);

    int64_t* a = (int64_t*)malloc(ARRAY_BYTES);
    int64_t* b = (int64_t*)malloc(ARRAY_BYTES);
    int64_t* c = (int64_t*)malloc(sizeof(int64_t));
    
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        a[i] = rand() % 100;  
        b[i] = rand() % 100;  
    }

    LARGE_INTEGER li;
    long long int start, end;
    double PCFreq, elapse, aveTime = 0.0;
    QueryPerformanceFrequency(&li);
    PCFreq = (double)(li.QuadPart);

    for (int i = 0; i < 30; i++) {
    QueryPerformanceCounter(&li);
    start = li.QuadPart;

        x86(ARRAY_SIZE, &c, a, b);
    
    QueryPerformanceCounter(&li);
    end = li.QuadPart;
    
    elapse = ((double)(end - start)) * 1000.0 / PCFreq;
    aveTime += elapse;
    printf("Iteration %d Time in x86 =  %f ns\n", i+1, elapse);
    }
    aveTime = aveTime / 30;
    printf("\nAverage Time in x86 =  %f ns\n", aveTime);
    printf("x86 Code Dot Product = %lld\n \n", c);
    int64_t c2 = 0;
    for (int i = 0; i < 30; i++) {
        QueryPerformanceCounter(&li);
        start = li.QuadPart;

        c2 = dotProduct(a, b, ARRAY_SIZE);

        QueryPerformanceCounter(&li);
        end = li.QuadPart;

        elapse = ((double)(end - start)) * 1000.0 / PCFreq;
        aveTime += elapse;
        printf("Iteration %d Time in C =  %f ns\n", i + 1, elapse);
    }
    aveTime = aveTime / 30;
    printf("\nAverage Time in C =  %f ns\n", aveTime);
    printf("C Code Dot Product = %lld\n \n", c2);

    return 0;
}
