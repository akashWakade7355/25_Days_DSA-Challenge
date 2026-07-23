// Topic : Carry Forward

/*
Question :
Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists.

Examples:

Input: arr[] = [1, 2, 0, 3]
Output: 2
Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3.

Input: arr[] = [1, 1, 1, 1]
Output: -1
Explanation: There is no equilibrium index in the array.

Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.

Constraints:
3 <= arr.size() <= 105
-104 <= arr[i] <= 104
*/

// solution :

class Solution
{
public:
    int findEquilibrium(vector<int> &arr)
    {
        // code here
        int totalSum = 0;

        for (int num : arr)
            totalSum += num;

        int leftSum = 0;

        for (int i = 0; i < arr.size(); i++)
        {

            int rightSum = totalSum - leftSum - arr[i];

            if (leftSum == rightSum)
                return i;

            leftSum += arr[i];
        }

        return -1;
    }
};


/*
# Approach

1. **Calculate the total sum of the array.**
   - Traverse the entire array once and store the sum of all elements in `totalSum`.

2. **Initialize the left sum.**
   - Set `leftSum = 0`.
   - Initially, there are no elements to the left of the first index.

3. **Traverse the array.**
   - For each index `i`, calculate the sum of elements on the right using:
     ```cpp
     rightSum = totalSum - leftSum - arr[i];
     ```
   - We subtract:
     - `leftSum` → Sum of elements before index `i`.
     - `arr[i]` → Current element.

4. **Check the equilibrium condition.**
   - If:
     ```cpp
     leftSum == rightSum
     ```
     then the current index is the equilibrium index.
   - Return the current index immediately since we need the **first** equilibrium point.

5. **Update the left sum.**
   - Add the current element to `leftSum`:
     ```cpp
     leftSum += arr[i];
     ```
   - Move to the next index.

6. **If no equilibrium index is found, return `-1`.**


# Time Complexity

- Calculating the total sum: **O(n)**
- Traversing the array to find the equilibrium index: **O(n)**

**Overall Time Complexity:** **O(n)**


# Space Complexity

- Only two extra variables (`totalSum` and `leftSum`) are used.

**Overall Space Complexity:** **O(1)**
*/