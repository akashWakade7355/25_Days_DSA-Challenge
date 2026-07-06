
/*
Question :
Given a mxn matrix, count the number of squares in the matrix.

Examples:

Input: m = 2, n = 2
Output: 5
Explanation: There are a total of 5 squares in a 2*2 matrix. Four 1*1 squares and one 2*2 square.

Input: m = 4, n = 3
Output: 20
Explanation: There are a total of 20 squares in a 4*3 matrix.

Constraints:
1 <= m,n <= 104

*/
// Solution

class Solution
{
public:
    int squaresInMatrix(int m, int n)
    {
        int ans = 0;
        for (int k = 1; k <= min(m, n); k++)
            ans += (m - k + 1) * (n - k + 1);

        return ans;
    }
};

// TC:0(min(m,n))

// SC:0(1)
/*
Approach:

Step 1:
A square can only be formed by taking an equal number of rows and columns.
So, for every possible side length k (1 <= k <= min(n, m)), we count the
number of k × k squares.

Step 2:
For a matrix of size n × m, the number of possible starting positions for
a k × k square is:
    Rows    = (n - k + 1)
    Columns = (m - k + 1)

Hence, the total number of k × k squares is:
    (n - k + 1) * (m - k + 1)

Step 3:
Iterate k from 1 to min(n, m) and add the number of k × k squares to the answer.

Finally, return the total count.
*/