#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct indices
{
    size_t i, j;
};

template<typename T>
class Matrix {
    vector<T> data;
public:
    size_t nrow, ncol;
    Matrix() : nrow{ 0 }, ncol{ 0 }, data{ vector<T>{} }{}
    Matrix(vector<T>&& data, size_t nrow, size_t ncol) : nrow{ nrow }, ncol{ ncol }, data{ data }{}
    void resize(size_t m, size_t n) {
        assert(m * n == nrow * ncol);
        nrow = m;
        ncol = n;
    }
    T& operator[](indices idx) {
        return data[idx.i * ncol + idx.j];
    }
};

int main() {
    Matrix<int> m{ vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, 4, 3 };
    m.resize(3, 4);
    for (size_t i = 0; i < m.nrow; i++)
    {
        for (size_t j = 0; j < m.ncol; j++)
        {
            printf("%2i ", m[{i, j}]);
        }
        cout << endl;
    }

}