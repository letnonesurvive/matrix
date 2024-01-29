#include "Matrix.h"
#include <iostream>
#include<cassert>

using namespace std;

int main()
{ 
    Matrix<int, -1> aMatrix;
    cout << aMatrix.get_default_value();
    aMatrix(1, 1) = 1;
    auto A = aMatrix (1, 1);
}
