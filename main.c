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

    const size_t ARRAY_SIZE = 1 << 20;
    int iteration = 30;

    const size_t ARRAY_BYTES = ARRAY_SIZE * sizeof(int64_t);
    printf("Number of elements = %zu\n\n", ARRAY_SIZE);

    int64_t* a = (int64_t*)malloc(ARRAY_BYTES);
    int64_t* b = (int64_t*)malloc(ARRAY_BYTES);
    int64_t c = 0;


    if (!a || !b) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(a);
        free(b);
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        a[i] = 1;  
        b[i] = 2;  
    }

    LARGE_INTEGER li;
    long long int start, end;
    double PCFreq, elapse, c_aveTime = 0.0, x86_aveTime = 0.0, xmm_aveTime = 0.0, ymm_aveTime = 0.0;
    QueryPerformanceFrequency(&li);
    PCFreq = (double)(li.QuadPart);

    // --------- C Program start ---------
    printf("============================================\n");
    printf("                 C Program\n");
    printf("============================================\n");
    int64_t c_answer = 0;
    for (int i = 0; i < iteration; i++) {
        QueryPerformanceCounter(&li);
        start = li.QuadPart;

        c_answer = dotProduct(a, b, ARRAY_SIZE);

        QueryPerformanceCounter(&li);
        end = li.QuadPart;

        elapse = ((double)(end - start)) * 1000.0 / PCFreq;
        c_aveTime += elapse;
        printf("Iteration %d Time in C =  %f ms\n", i + 1, elapse);
    }
    c_aveTime = c_aveTime / iteration;

    printf("\nAverage Time in C =  %f ms\n", c_aveTime);
    printf("C Code Dot Product = %lld\n \n", c_answer);

    // --------- C Program end ---------

    // --------- x86-64 start ---------
    printf("============================================\n");
    printf("              X86-64 Program\n");
    printf("============================================\n");
    int64_t x86_answer = 0;
    for (int i = 0; i < iteration; i++) {
    QueryPerformanceCounter(&li);
    start = li.QuadPart;

        x86(ARRAY_SIZE, &c, a, b);
    
    QueryPerformanceCounter(&li);
    end = li.QuadPart;
    
    elapse = ((double)(end - start)) * 1000.0 / PCFreq;
    x86_aveTime += elapse;
    printf("Iteration %d Time in x86 =  %f ms\n", i+1, elapse);
    }
    x86_aveTime = x86_aveTime / iteration;

    printf("\nAverage Time in x86 =  %f ms\n", x86_aveTime);
    printf("x86 Code Dot Product = %lld\n \n", c);

    x86_answer = c;

    // --------- x86-64 end ---------

    // --------- xmm start ---------
    printf("============================================\n");
    printf("                XMM Program\n");
    printf("============================================\n");
    int64_t xmm_answer = 0;
    for (int i = 0; i < iteration; i++) {
        QueryPerformanceCounter(&li);
        start = li.QuadPart;

        xmm(ARRAY_SIZE, &c, a, b);

        QueryPerformanceCounter(&li);
        end = li.QuadPart;

        elapse = ((double)(end - start)) * 1000.0 / PCFreq;
        xmm_aveTime += elapse;
        printf("Iteration %d Time in Xmm =  %f ms\n", i + 1, elapse);
    }
    xmm_aveTime = xmm_aveTime / iteration;
    printf("\nAverage Time in Xmm =  %f ms\n", xmm_aveTime);
    printf("Xmm Code Dot Product = %lld\n \n", c);

    xmm_answer = c;

    // --------- xmm end ---------

    // --------- ymm start ---------
    printf("============================================\n");
    printf("                YMM Program\n");
    printf("============================================\n");
    int64_t ymm_answer = 0;
    for (int i = 0; i < iteration; i++) {
        QueryPerformanceCounter(&li);
        start = li.QuadPart;

        ymm(ARRAY_SIZE, &c, a, b);

        QueryPerformanceCounter(&li);
        end = li.QuadPart;

        elapse = ((double)(end - start)) * 1000.0 / PCFreq;
        ymm_aveTime += elapse;
        printf("Iteration %d Time in Ymm =  %f ms\n", i + 1, elapse);
    }
    ymm_aveTime = ymm_aveTime / iteration;
    printf("\nAverage Time in Ymm =  %f ms\n", ymm_aveTime);
    printf("Ymm Code Dot Product = %lld\n \n", c);

    ymm_answer = c;

    // --------- ymm end ---------

    // --------- error checking start ---------
    printf("=============================================================\n");
    printf("                       Error Checking\n");
    printf("=============================================================\n");
    const char* programs[] = { "C", "X86-64", "XMM", "YMM" };
    int64_t answers[] = { c_answer, x86_answer, xmm_answer, ymm_answer };
    double times[] = { c_aveTime, x86_aveTime, xmm_aveTime, ymm_aveTime };
    const char* padding[] = { "       ", "  ", "     ", "     " };

    for (int i = 0; i < 4; i++) {
        if (answers[i] == c_answer) {
            printf("%s program is correct.%s(Avg. Time: [%f ms])\n",
                programs[i], padding[i], times[i]);
        }
        else {
            printf("Error. %s program is incorrect\n", programs[i]);
        }
    }

    printf("=============================================================\n");
    // --------- error checking end ---------

    free(a);
    free(b);

    return 0;
}

