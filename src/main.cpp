#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
#include "Adder/Adder.h"
#include <limits.h>

using namespace std;

void square(vector<vector<int>> *arr)
{
    for (auto row : *arr)
    {
        for (auto num : row)
        {
            cout << pow(num, 2) << endl;
        }
    }
    float a, b;
    scanf("%f", &a);
    scanf("%f", &b);
    cout << adder::add(a, b) << endl;
}

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
{
    for (auto &row : A)
    {
        reverse(row.begin(), row.end());
        for (auto &pixel : row)
        {
            pixel ^= 0x1;
        }
    }
    return A;
}

void hello_size()
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

    int32_t i1 = INT32_MAX;
    printf("int32_t takes up %d bytes. MIN: %d; MAX: %d\n", sizeof(i1), i1, INT32_MIN);
    int64_t i2 = INT64_MAX;
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

// int main()
// {
//     vector<int> v{1, 2, 3};
//     vector<int> w{4, 5, 6};
//     vector<vector<int>> z{v, w};
//     square(&z);
//     return 0;
// }
int main()
{
    // int32_t x{5 };
    // auto p_x = &x;
    hello_size();
    unique_ptr<int32_t> p_x(new int32_t(5));
    *p_x = 10;
    printf("%p: %d\n", &p_x, *p_x);

    int32_t y[5]{1, 2, 3, 4, 5};
    int32_t(*p_y)[5] = &y;
    for (int32_t &e : y)
    {
        e = e + 1;
    }
    for (int32_t &e : y)
    {
        cout << e << endl;
    }
    for (int32_t &e : *p_y)
    {
        e = e + 1;
    }

    return 0;
}
