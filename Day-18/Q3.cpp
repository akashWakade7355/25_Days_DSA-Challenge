// Topic : Carry forward

/*
Question :
Given an array arr, find the floor of average of the prefix array at every index.

Examples:

Input: arr[] = [10, 20, 30, 40, 50]
Output: [10, 15, 20, 25, 30]
Explanation: 10 / 1 = 10, (10 + 20) / 2 = 15, (10 + 20 + 30) / 3 = 20 and so on.

Input: arr[] = [12, 1]
Output: [12, 6]
Constraints:
1 ≤ arr.size ≤ 105
1 ≤ arr[i] ≤ 106
*/

// solution :

class Solution
{
public:
    vector<int> prefixAvg(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> ps(n);

        ps[0] = arr[0];

        for (int i = 1; i < n; i++)
            ps[i] = ps[i - 1] + arr[i];

        for (int i = 0; i < n; i++)
            ps[i] = ps[i] / (i + 1);

        return ps;
    }
};

/*
# Approach

### Step 1: Build the Prefix Sum Array
- Create a prefix sum array `ps`.
- Initialize `ps[0] = arr[0]`.
- For every index `i` from `1` to `n-1`, compute:
  - `ps[i] = ps[i-1] + arr[i]`
- Now, `ps[i]` stores the sum of all elements from index `0` to `i`.


### Step 2: Calculate the Prefix Average
- Traverse the prefix sum array.
- At every index `i`, the prefix contains `(i + 1)` elements.
- Compute the floor of the average using integer division:
  - `ps[i] = ps[i] / (i + 1)`
- Since C++ integer division automatically returns the floor value, no extra operation is required.


### Step 3: Return the Result
- The modified prefix sum array now contains the floor of the prefix average at every index.
- Return this array.


# Time Complexity (TC)

- Building the prefix sum array: **O(n)**
- Computing the prefix averages: **O(n)**

**Overall Time Complexity:** **O(n)**


# Space Complexity (SC)

- Prefix sum array of size `n`.

**Overall Space Complexity:** **O(n)**
*/