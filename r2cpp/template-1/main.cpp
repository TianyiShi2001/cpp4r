// * References
// *    - https://stackoverflow.com/questions/1936399/c-array-operator-with-multiple-arguments
// *    - https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// struct indices
// {
//     size_t i, j;
// };

template<typename T>
class Matrix {
    vector<T> data;
public:
    size_t nrow, ncol;
    // * constructors
    Matrix() : nrow{ 0 }, ncol{ 0 }, data{ vector<T>{} }{}
    Matrix(vector<T>&& data, size_t nrow, size_t ncol) : nrow{ nrow }, ncol{ ncol }, data{ data }{}
    // * destructor
    ~Matrix() { delete[] data; }
    // * reisize
    void resize(size_t m, size_t n) {
        assert(m * n == nrow * ncol);
        nrow = m;
        ncol = n;
    }
    // * index
    T& operator()(size_t i, size_t j) {
        return data[i * ncol + j];
    }
    // T& operator[](indices idx) {
    //     return data[idx.i * ncol + idx.j];
    // }

};

int main() {
    Matrix<int> m{ vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, 4, 3 };
    m.resize(3, 4);
    for (size_t i = 0; i < m.nrow; i++)
    {
        for (size_t j = 0; j < m.ncol; j++)
        {
            printf("%2i ", m(i, j));
        }
        cout << endl;
    }

}