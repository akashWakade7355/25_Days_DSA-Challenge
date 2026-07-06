// Topic : 2D Matrix

/*
Question :
Given a square matrix mat[][] of size n*n, return an array of two elements containing two
values: the sum of Upper Triangle elements and the sum of Lower Triangle elements. Upper
Triangle consists of elements on the diagonal and above it. The lower triangle consists
 of elements on the diagonal and below it.

Examples:

Input: n = 3, mat[][] = [[6, 5, 4],
                       [1, 2, 5],
                       [7, 9, 7]]
Output: [29, 32]
Explanation:
Upper triangular matrix:
6 5 4
  2 5
    7
Sum of these elements is 6 + 5 + 4 + 2 + 5 + 7 = 29.
Lower triangular matrix:
6
1 2
7 9 7
Sum of these elements is 6 + 1 + 2 + 7 + 9 + 7 = 32.
Input: n = 2, mat[][] = [[1, 2],
                       [3, 4]]
Output: [7, 8]
Explanation:
Upper triangular matrix:
1 2
  4
Sum of these elements are 1 + 2 + 4 = 7.
Lower triangular matrix:
1
3 4
Sum of these elements are 1 + 3 + 4 = 8.
Constraints:
1 ≤ n ≤ 500
1 ≤ mat[i][j] ≤ 1000
*/

// solution

class Solution
{
public:
    vector<int> sumTriangles(vector<vector<int>> &mat)
    {
        // code here
        int Uppersum = 0, Lowersum = 0;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (j >= i)
                    Uppersum += mat[i][j];
                if (i >= j)
                    Lowersum += mat[i][j];
            }

        return {Uppersum, Lowersum};
    }
};

// TC:0(m*n)

// SC:0(1)

/*
Approach :

Step 1:
Create two variables, 'UpperSum' and 'LowerSum', and initialize
both of them to 0. These variables will store the sum of the
upper triangular and lower triangular elements respectively.

Step 2:
Traverse the entire matrix using two nested loops.

Step 3:
For every element at index (i, j):

    • If the column index is greater than or equal to the row
      index (j >= i), then the element belongs to the upper
      triangular matrix. Add it to 'UpperSum'.

    • If the row index is greater than or equal to the column
      index (i >= j), then the element belongs to the lower
      triangular matrix. Add it to 'LowerSum'.

Note:
The diagonal elements satisfy both conditions (i == j), so they
are included in both the upper and lower triangular sums.

Step 4:
After traversing the entire matrix, return both sums as a vector.

        return {UpperSum, LowerSum};
*/