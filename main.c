#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void x86(size_t n, int64_t* z, int64_t* x, int64_t* y);
extern void ymm(size_t n, int64_t* z, int64_t* x, int64_t* y);
extern void xmm(size_t n, int64_t* z, int64_t* x, int64_t* y);

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
    int64_t c = 0;


    if (!a || !b) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(a);
        free(b);
        return EXIT_FAILURE;
    }

    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        a[i] = rand() % 100;  
        b[i] = rand() % 100;  
    }

    LARGE_INTEGER li;
    long long int start, end;
    double PCFreq, elapse, c_aveTime = 0.0, x86_aveTime = 0.0, xmm_aveTime = 0.0, ymm_aveTime = 0.0;
    QueryPerformanceFrequency(&li);
    PCFreq = (double)(li.QuadPart);

    // --------- C Program start ---------
    int64_t c_answer = 0;
    for (int i = 0; i < 30; i++) {
        QueryPerformanceCounter(&li);
        start = li.QuadPart;

        c_answer = dotProduct(a, b, ARRAY_SIZE);

        QueryPerformanceCounter(&li);
        end = li.QuadPart;

        elapse = ((double)(end - start)) * 1000.0 / PCFreq;
        c_aveTime += elapse;
        printf("Iteration %d Time in C =  %f ns\n", i + 1, elapse);
    }
    c_aveTime = c_aveTime / 30;
    printf("\nAverage Time in C =  %f ns\n", c_aveTime);
    printf("C Code Dot Product = %lld\n \n", c_answer);

    // --------- C Program end ---------

    // --------- x86-64 start ---------
    int64_t x86_answer = 0;
    for (int i = 0; i < 30; i++) {
    QueryPerformanceCounter(&li);
    start = li.QuadPart;

        x86(ARRAY_SIZE, &c, a, b);
    
    QueryPerformanceCounter(&li);
    end = li.QuadPart;
    
    elapse = ((double)(end - start)) * 1000.0 / PCFreq;
    x86_aveTime += elapse;
    printf("Iteration %d Time in x86 =  %f ns\n", i+1, elapse);
    }
    x86_aveTime = x86_aveTime / 30;
    printf("\nAverage Time in x86 =  %f ns\n", x86_aveTime);
    printf("x86 Code Dot Product = %lld\n \n", c);

    x86_answer = c;
    // --------- x86-64 end ---------

    // --------- xmm start ---------
    int64_t xmm_answer = 0;
    for (int i = 0; i < 30; i++) {
        QueryPerformanceCounter(&li);
        start = li.QuadPart;

        xmm(ARRAY_SIZE, &c, a, b);

        QueryPerformanceCounter(&li);
        end = li.QuadPart;

        elapse = ((double)(end - start)) * 1000.0 / PCFreq;
        xmm_aveTime += elapse;
        printf("Iteration %d Time in Xmm =  %f ns\n", i + 1, elapse);
    }
    xmm_aveTime = xmm_aveTime / 30;
    printf("\nAverage Time in Xmm =  %f ns\n", xmm_aveTime);
    printf("Xmm Code Dot Product = %lld\n \n", c);

    xmm_answer = c;
    // --------- xmm end ---------

    // --------- ymm start ---------
    int64_t ymm_answer = 0;
    for (int i = 0; i < 30; i++) {
        QueryPerformanceCounter(&li);
        start = li.QuadPart;

        ymm(ARRAY_SIZE, &c, a, b);

        QueryPerformanceCounter(&li);
        end = li.QuadPart;

        elapse = ((double)(end - start)) * 1000.0 / PCFreq;
        ymm_aveTime += elapse;
        printf("Iteration %d Time in Ymm =  %f ns\n", i + 1, elapse);
    }
    ymm_aveTime = ymm_aveTime / 30;
    printf("\nAverage Time in Ymm =  %f ns\n", ymm_aveTime);
    printf("Ymm Code Dot Product = %lld\n \n", c);

    ymm_answer = c;
    // --------- ymm end ---------

    // --------- error checking start ---------

    printf("----------------------------------------\n");
    // x86-64
    if (x86_answer == c_answer) {
        printf("x86-64 program is correct\n");
    }
    else {
        printf("Error. x86-64 program is incorrect\n");
    }

    // xmm
    if (xmm_answer == c_answer) {
        printf("xmm program is correct\n");
    }
    else {
        printf("Error. xmm program is incorrect\n");
    }

    // ymm
    if (ymm_answer == c_answer) {
        printf("ymm program is correct\n");
    }
    else {
        printf("Error. ymm program is incorrect\n");
    }

    printf("----------------------------------------\n");
    free(a);
    free(b);


    return 0;
}

