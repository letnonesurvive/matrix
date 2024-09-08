# Task

Design a 2-dimensional sparse infinite matrix filled with default values. The matrix should only store occupied elements—values that have been assigned at least once. Assigning a default value to a cell frees up the cell.

You need to be able to answer the question: how many cells are actually occupied? You should also be able to iterate over all occupied cells. The order does not matter. Return the position of the cell and its value. When reading an element from a free cell, return the default value.

```
// Infinite matrix of int filled with -1
 Matrix<int, -1> matrix;
 assert(matrix.size() == 0); // all cells are free
 auto a = matrix[0][0];
 assert(a == -1);
 assert(matrix.size() == 0);
 matrix[100][100] = 314;
 assert(matrix[100][100] == 314);
 assert(matrix.size() == 1);
 // Output will be one line
 // 100100314
 for(auto c: matrix)
 {
   int x;
   int y;
   int v;
   std::tie(x, y, v) = c;
   std::cout << x << y << v << std::endl;
 }
```

When running the program, you need to create a matrix with a default value of 0, fill the main diagonal of the matrix (from [0,0] to [9,9]) with values from 0 to 9.

Fill the secondary diagonal (from [0,9] to [9,0]) with values from 9 to 0.

You need to output a fragment of the matrix from [1,1] to [8,8]. Use a space between columns. Each row of the matrix should be on a new line in the console.

Output the number of occupied cells.

Output all occupied cells along with their positions.
