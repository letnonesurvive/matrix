#include "Matrix.h"
#include <iostream>
#include <cassert>

using namespace std;

int main()
{ 
    Matrix<int, 0> aMatrix;

    assert(aMatrix.size() == 0);

    for (int i = 0; i < 10; ++i) {
        aMatrix (i, i) = i;
    }

    for (int i = 0, j = 9 - i; i < 10; ++i, --j) {
        aMatrix (i, j) = j;
    }

    std::pair<size_t, size_t> from = {1,1};
    std::pair<size_t, size_t> to = { 8,8 };
    aMatrix.Print (from, to);


    for (const auto& anElement : aMatrix) {
        size_t x = anElement.first.first;
        size_t y = anElement.first.second;
        auto value = anElement.second;
        cout << "[" << x << ',' << y << "] = " << value << endl;
    }

    cout << aMatrix << endl;

    assert(aMatrix.size() == 18);
}
