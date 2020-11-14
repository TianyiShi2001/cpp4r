#include <iostream>
#include <assert.h>
#include <vector>
#include <numeric>

constexpr double LIGHT_SPEED = 2.99792458e8;

double sum(const std::vector<double> &v)
{
    double ret = 0.;
    for (auto n : v)
    {
        ret += n;
    }
    return ret;
    // return std::accumulate((*v).start(), (*v).end(), 0, std::plus<double>());
}

int main()
{
    int a{5};
    int &r_a = a;  // create a reference
    int *p_a = &a; // create a pointer
    printf("| a|r_a|*p_a|     p_a      |\n");
    a = 10; // mutate the value
    printf("|%d| %d|  %d|%p|\n", a, r_a, *p_a, p_a);
    r_a = 15; // mutate via reference
    printf("|%d| %d|  %d|%p|\n", a, r_a, *p_a, p_a);
    *p_a = 20; // mutate via pointer
    printf("|%d| %d|  %d|%p|\n", a, r_a, *p_a, p_a);

    int f;
    char c = 5;
    printf("");

    int x = 0;
    int y = 0;
    int *p = &x;
    int *q = &y;
    int **pp = &p;
    pp = &q; //*pp = q
    **pp = 4;
    assert(y == 4);
    assert(x == 0);

    int l = 5;
    int &m = l;
    assert(m == 5);
}