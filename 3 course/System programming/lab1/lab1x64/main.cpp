#include <stdio.h>
#include <stdint.h>

extern "C" int32_t calc(int32_t, int16_t, int32_t);
extern "C" uint32_t K = 0x4569600F;  // K CONST IN HEX

int main() {
    int32_t a;
    int16_t c;
    int32_t d;
    int32_t res;

    printf("Enter numbers:\n");
    printf("K = %u\n", K);
    printf("A = ");
    scanf_s("%d", &a);
    printf("C = ");
    scanf_s("%hd", &c);
    printf("D = ");
    scanf_s("%d", &d);

    printf("A + (4 * C) - D / 2 + K = %d\n", (a + (4 * c) - (d / 2) + K));

    res = calc(a, c, d);

    return 0;
}