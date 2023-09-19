#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

int main() {
    printf("%lld\r\n", LONG_LONG_MAX);
    printf("%f\r\n", FLT_MAX);
    printf("%d\r\n", sizeof(long double));
    return 0;
}