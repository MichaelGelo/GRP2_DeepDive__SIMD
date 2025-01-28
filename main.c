#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>

extern void x86(size_t n, int64_t* z, int64_t* x, int64_t* y);

int main() {
    const size_t ARRAY_SIZE = 10;
    printf("Number of elements = %zu\n", ARRAY_SIZE);

    int64_t a[10] = { -1, -2, -3, -4, -5, 6, 7, 8, 9, 10 };
    int64_t b[10] = { 11, 12, 13, 14, 15, -16, -17, -18, -19, -20 };
    int64_t c = 0;

    x86(ARRAY_SIZE, &c, a, b);

    printf("Dot product = %lld\n", c);

    return 0;
}
