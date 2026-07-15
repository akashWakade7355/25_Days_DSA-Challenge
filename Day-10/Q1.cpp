// Topic : Hasing 

/*
Question :

Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not. 

Examples:

Input: arr[] = [4, 2, -3, 1, 6]
Output: true
Explanation: 2, -3, 1 is the subarray with a sum of 0.
Input: arr = [4, 2, 0, 1, 6]
Output: true
Explanation: 0 is one of the elements in the array so there exist a subarray with sum 0.
Input: arr = [1, 2, -1]
Output: false

Constraints:

1 ≤ arr.size() ≤ 105
-105 ≤ arr[i] ≤ 105
*/

// solution :


class Solution {
  public:
    bool subArrayExists(vector<int>& arr) {
        // code here
         unordered_set<long long> st;
        long long prefixSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            if (prefixSum == 0)
                return true;

            if (arr[i] == 0)
                return true;

            if (st.find(prefixSum) != st.end())
                return true;

            st.insert(prefixSum);
        }

        return false;
    }
};


// TC:0(n)

// SC:0(n)

/*
Apprach :

Step 1:
Initialize a variable `prefixSum = 0` to store the cumulative sum of elements while traversing the array.

Step 2:
Create an `unordered_set` to store all the prefix sums encountered so far.

Step 3:
Traverse the array from left to right.

Step 4:
For each element, add its value to `prefixSum`.

Step 5:
Check if `prefixSum` is equal to `0`.
- If yes, return `true` because the subarray from index `0` to the current index has a sum of `0`.

Step 6:
Check if `prefixSum` already exists in the `unordered_set`.
- If it exists, return `true` because the subarray between the previous occurrence of the same prefix sum and the current index has a sum of `0`.

Step 7:
If neither condition is satisfied, insert the current `prefixSum` into the `unordered_set`.

Step 8:
After traversing the entire array, if no zero-sum subarray is found, return `false`.
*/