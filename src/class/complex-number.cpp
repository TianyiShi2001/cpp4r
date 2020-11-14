#include <iostream>
#include <cassert>

class Complex
{
    int re, im;

public:
    Complex() : re{0}, im{0} {};
    Complex(int re) : re{re}, im{0} {};
    Complex(int re, int im) : re{re}, im{im} {};
    int real() const { return re; }
    Complex operator+(Complex rhs)
    {
        return Complex(re + rhs.re, im + rhs.im);
    }
    bool operator==(Complex rhs) const
    {
        return re == rhs.re && im == rhs.im;
    }
    bool operator!=(Complex rhs) const
    {
        return !(*this == rhs);
    }
};

int main()
{
    auto a = Complex(5);
    auto b = Complex(3, 8);
    auto c = a + b;
    assert(c == (Complex(8, 8)));
    assert(c != (Complex(9, 8)));
}