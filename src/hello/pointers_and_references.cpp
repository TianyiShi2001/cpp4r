#include <iostream>
#include <assert.h>
#include <vector>
#include <numeric>

constexpr double LIGHT_SPEED = 2.99792458e8;

namespace basic
{
    void pointer()
    {
        int a = 5;
        // * to make a pointer of `a`, use the `&` operator (reads "the memory address of...")
        // * the pointer that points to type `T` has type `T*`.
        int* pa = &a;
        // * to print the actual memory address, use the `%p` format specifier
        // * to dereference the pointer (i.e. read the value of the referent), use the `*`
        // * operator (dereference operator)
        printf("The integer at memory address %p is: %d\n", pa, *pa);
        // * you can use `auto`
        // * note it's not `auto* pa1 = &a;`
        auto pa1 = &a;
        assert(*pa == *pa1);
        // ! Unlike in Rust, you cannot make a pointer directly to a literal.
        // int pb = &10;
    }

    void reference() {
        int a = 5;
        // * to make a reference to `a`, you don't need an operator on a.
        // * the type of a reference to type `T` is `T&`
        int& ra = a;
        // * to read the value of the referent you do not (and cannot) use a dereference operator
        // * think of a reference as an "alias"
        printf("a: %d; ra: %d\n", a, ra);
        // * you can use `auto`
        // * note it's not `auto ra1 = a;`, which would otherwise making `ra1` an `int`
        auto& ra1 = a;
        assert(ra == ra1);
        // ! You cannot make a reference directly to a literal.
        // int& b = 10;
    }

    void mutability() {
        // * both a reference and a pointer can be used to mutate the referent.
        int a{ 5 };
        int& r_a = a;  // create a reference
        int* p_a = &a; // create a pointer
        printf("| a|r_a|*p_a|     p_a      |\n");
        a = 10; // mutate the value directly
        printf("|%d| %d|  %d|%p|\n", a, r_a, *p_a, p_a);
        r_a = 15; // mutate via reference
        printf("|%d| %d|  %d|%p|\n", a, r_a, *p_a, p_a);
        *p_a = 20; // mutate via pointer
        printf("|%d| %d|  %d|%p|\n", a, r_a, *p_a, p_a);
    }

    void difference() {
        // * So what's the different between a pointer and a reference apart from
        // * the semantics?
        {
            int x = 0;
            int y = 0;
            int* px = &x;
            int* py = &y;
            // * You can make a pointer to a pointer
            // * every time you do so, you append to the pointer type one more asterisk
            int** ppx = &px;
            // * of course you can use `auto`
            auto ppx_1 = &px; // `ppx_1` has the same type as `ppx`, which is `int**`
            // * and mutate the pointer via the pointer to this pointer
            ppx = &py; //*ppx = py
            // * and do whatever you can imagine
            **ppx = 4;
            // ? what's the value of x and y now?
            assert(y == 4);
            assert(x == 0);
        }
        {
            int x = 0;
            int& rx = x;
            // * You cannot make a reference to a reference.
            {
                // ? so what does the following code do?
                auto& rrx = rx;
            }
            // * the above code desugars to:
            int& rrx = rx;
            // ! not `int&& rrx = rx;`
            // * A reference isn't really an independent "thing". It's just an alias. It has the
            // * same memory address as the referent. So when you try to make a
            // * reference to a reference, what it actually does is to make another
            // * reference to the original referent.
            // * You can check the memory addresses:
            printf("%p, %p, %p\n", &x, &rx, &rrx);
            int y = 10;
            int& ry = y;
            // * You cannot re-assign a reference.
            // ? so what does the following code do?
            rx = ry;
            // * it simply mutates the value of `x` to the value of `y`
            assert(x == 10);
            assert(x == y);
        }
    }
    void main() {
        pointer();
        reference();
        difference();
    }
} // namespace basic

double sum(const std::vector<double>& v)
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
    basic::main();
}