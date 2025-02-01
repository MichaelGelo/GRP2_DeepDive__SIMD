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
    const size_t ARRAY_SIZE = 10;
    printf("Number of elements = %zu\n", ARRAY_SIZE);

    int64_t a[10] = { -1, -2, -3, -4, -5, 6, 7, 8, 9, 10 };
    int64_t b[10] = { 11, 12, 13, 14, 15, -16, -17, -18, -19, -20 };
    int64_t c = 0;

    LARGE_INTEGER li;
    long long int start, end;
    double PCFreq, elapse;
    QueryPerformanceFrequency(&li);
    PCFreq = (double)(li.QuadPart);

    QueryPerformanceCounter(&li);
    start = li.QuadPart;

    for (int i = 0; i < 30; i++) {
        x86(ARRAY_SIZE, &c, a, b);
    }

    QueryPerformanceCounter(&li);
    end = li.QuadPart;
    elapse = ((double)(end - start)) * 1000.0 / PCFreq;
    printf("Time in x86 =  %f ns\n", elapse);

    printf("x86 Code Dot Product = %lld\n \n", c);

    QueryPerformanceCounter(&li);
    start = li.QuadPart;

    int64_t c2 = 0;
    for (int j = 0; j < 30; j++) {
        c2 = dotProduct(a, b, ARRAY_SIZE);
    }

    QueryPerformanceCounter(&li);
    end = li.QuadPart;
    elapse = ((double)(end - start)) * 1000.0 / PCFreq;
    printf("Time in C =  %f ns\n", elapse);

    printf("C Code Dot Product = %lld\n \n", c2);

    return 0;
}
