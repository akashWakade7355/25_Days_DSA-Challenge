// Topic : Carry Forward

/*
Question :
You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element.
Notice that the index of the elements may change after the removal.

For example, if nums = [6,1,7,4,1]:

Choosing to remove index 1 results in nums = [6,7,4,1].
Choosing to remove index 2 results in nums = [6,1,4,1].
Choosing to remove index 4 results in nums = [6,1,7,4].
An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the number of indices that you could choose such that after the removal, nums is fair.


Example 1:

Input: nums = [2,1,6,4]
Output: 1
Explanation:
Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
There is 1 index that you can remove to make nums fair.
Example 2:

Input: nums = [1,1,1]
Output: 3
Explanation: You can remove any index and the remaining array is fair.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: You cannot make a fair array after removing any index.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
*/

// solution :

class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {
        int rightEven = 0;
        int rightOdd = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
                rightEven += nums[i];
            else
                rightOdd += nums[i];
        }

        int leftEven = 0;
        int leftOdd = 0;

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (i % 2 == 0)
                rightEven -= nums[i];
            else
                rightOdd -= nums[i];

            int newEven = leftEven + rightOdd;
            int newOdd = leftOdd + rightEven;

            if (newEven == newOdd)
                ans++;

            if (i % 2 == 0)
                leftEven += nums[i];
            else
                leftOdd += nums[i];
        }

        return ans;
    }
};

/*
# Approach

1. **Calculate the sum of elements at even and odd indices.**
   - Traverse the array once.
   - Store the sum of elements at even indices in `rightEven`.
   - Store the sum of elements at odd indices in `rightOdd`.
   - Initially, all elements are considered to be on the **right side** of the current index.

2. **Initialize left-side sums.**
   - `leftEven = 0`
   - `leftOdd = 0`
   - These variables will store the sums of elements that have already been processed.

3. **Traverse the array to simulate removing each index.**
   - Before checking, remove the current element from the corresponding right-side sum.
     - If the current index is even, subtract it from `rightEven`.
     - Otherwise, subtract it from `rightOdd`.

4. **Compute the new even and odd sums after removal.**
   - After removing an element, all elements to its right shift one position.
   - Hence, their parity changes:
     - Right even-indexed elements become odd.
     - Right odd-indexed elements become even.
   - Therefore,
     ```
     newEven = leftEven + rightOdd
     newOdd = leftOdd + rightEven
     ```

5. **Check if the array becomes fair.**
   - If
     ```
     newEven == newOdd
     ```
     then removing the current index makes the array fair.
   - Increment the answer.

6. **Move the current element to the left side.**
   - After processing the current index, include it in the left sums.
     - If the index is even:
       ```
       leftEven += nums[i]
       ```
     - Otherwise:
       ```
       leftOdd += nums[i]
       ```

7. **Return the final count.**
   - After checking every index, return the number of valid indices.


# Time Complexity

- First traversal to calculate even and odd sums: **O(n)**
- Second traversal to check every removal: **O(n)**

**Overall Time Complexity:** **O(n)**


# Space Complexity

- Only a few integer variables are used (`leftEven`, `leftOdd`, `rightEven`, `rightOdd`, `ans`).

**Overall Space Complexity:** **O(1)**
*/