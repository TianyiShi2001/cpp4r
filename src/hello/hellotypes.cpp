#include <iostream>
#include <limits.h>

int main()
{
    int i = INT_MAX;
    printf("int takes up %d bytes. MIN: %d; MAX: %d\n", sizeof(i), i, INT_MIN);
    long l = LONG_MAX;
    printf("long takes up %d bytes. MIN: %d; MAX: %li\n", sizeof(l), l, LONG_MIN);
    long long ll = LONG_LONG_MAX;
    // 8 bytes; no more.
    printf("long takes up %d bytes. MIN: %d; MAX: %lli\n", sizeof(ll), ll, LONG_LONG_MIN);
    short si = SHRT_MAX;
    printf("short takes up %d bytes. MIN: %d; MAX: %d\n", sizeof(si), si, SHRT_MIN);
    char c = CHAR_MAX;
    printf("char takes up %d byte. MIN: %d; MAX: %d\n", sizeof(c), c, CHAR_MIN);
    unsigned char uc = UCHAR_MAX;
    printf("unsigned char takes up %d byte. MAX: %d\n", sizeof(uc), uc);

    int32_t i1{INT32_MAX};
    printf("int32_t takes up %d bytes. MIN: %d; MAX: %d\n", sizeof(i1), i1, INT32_MIN);
    int64_t i2{INT64_MAX};
    printf("int64_t takes up %d bytes. MIN: %d; MAX: %li\n", sizeof(i2), i2, INT64_MIN);
    // there isn't `int128_t` yet
    int16_t i3 = INT16_MAX;
    printf("int16_t takes up %d bytes. MIN: %d; MAX: %d\n", sizeof(i3), i3, INT16_MIN);
    int8_t i4 = INT8_MAX;
    printf("int8_t takes up %d byte. MIN: %d; MAX: %d\n", sizeof(i4), i4, INT8_MIN);
    uint64_t u = UINT64_MAX;
    printf("uint64_t takes up %d bytes. MAX: %lu\n", sizeof(u), u);
    size_t s = SIZE_MAX;
    printf("size_t takes up %d bytes. MAX: %lu\n", sizeof(s), s);
}