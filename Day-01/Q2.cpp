// Topic : 2D Matrix

/*
Question:
You are given two square matrices, a[][] and b[][], each of size n x n. Your task is to compute the sum of these two matrices and store the result in the matrix a[][] itself.

Examples:

Input: a[][] = [[1, 2], [3, 4]],
       b[][] = [[4, 3], [2, 1]]
Output: [[5, 5], [5, 5]]
Explanation: The will be: [[5, 5], [5, 5]] on adding the corresponding elements of both matrices.
Input: a[][] = [[7, 8], [9, 10]],
       b[][] = [[1, 2], [3, 4]]
Output: [[8, 10], [12, 14]]
Explanation: The result will be [[8, 10], [12, 14]] after adding the corresponding elements of both matrices.
Constraints:
1 <= n <= 100
*/

// solution

class Solution
{
public:
    void Addition(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB)
    {
        // Code here
        int n = matrixA.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrixA[i][j] += matrixB[i][j];
    }
};

// TC:0(n^2)

// SC:0(1)

/*
Approach:

Step 1:
Since both matrices are of size n × n, traverse each element using
two nested loops.

Step 2:
For every cell (i, j), add the corresponding element of matrixB
to matrixA and store the result back in matrixA.

    matrixA[i][j] = matrixA[i][j] + matrixB[i][j];

Step 3:
After traversing all the elements, matrixA will contain the sum
of both matrices.

*/