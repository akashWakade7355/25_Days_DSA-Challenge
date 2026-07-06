// Tpoic : 2D Matrix

/*
Question :

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-109 <= matrix[i][j] <= 109
*/

// solution

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        vector<int> n;

        for (int i = 0; i < matrix.size(); i++)
            n.push_back(0);

        vector<vector<int>> Tmatrix;

        for (int i = 0; i < matrix[0].size(); i++)
            Tmatrix.push_back(n);

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                Tmatrix[j][i] = matrix[i][j];

        return Tmatrix;
    }
};

// TC:0(n*m)

// SC:0(1)

/*
Approach :

Step 1:
Calculate the number of rows and columns of the given matrix.
Let the matrix be of size n × m.

Step 2:
Create a vector<int> named 'n' that will represent a single row
of the transposed matrix.

Step 3:
Since the transposed matrix will have 'n' columns (equal to the
number of rows of the original matrix), push the value 0 into
vector 'n' exactly 'n' times. This initializes one row of the
transposed matrix with all elements as 0.

Step 4:
Create a vector<vector<int>> named 'Tmatrix' to store the
transpose of the given matrix.

Step 5:
Since the transposed matrix will have 'm' rows (equal to the
number of columns of the original matrix), push the vector 'n'
into 'Tmatrix' exactly 'm' times. This creates an m × n matrix
initialized with 0s.

Step 6:
Traverse the original matrix using two nested loops.

Step 7:
For every element present at index (i, j) in the original matrix,
store it at index (j, i) in the transposed matrix.

        Tmatrix[j][i] = matrix[i][j];

Step 8:
After all the elements are copied, return the transposed matrix.
*/