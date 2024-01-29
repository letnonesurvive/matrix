#include "Matrix.h"
#include <iostream>
#include<cassert>

using namespace std;

int main()
{ 
    Matrix<int> aMatrix(-1);

    assert(aMatrix.size() == 0);

    int aVar = aMatrix[0][0];

    (void)aVar;
    /*assert(a == -1);
    assert(aMatrix.size() == 0);

    aMatrix[0][0] = 314;*/

    //aMatrix[0] = aVar;
}
