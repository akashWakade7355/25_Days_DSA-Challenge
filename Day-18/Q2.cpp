// Topic : Carry Forward

/*
Question :
You are given an integer array nums of length n.

A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:

Left subarray contains indices [0, i].
Right subarray contains indices [i + 1, n - 1].
Return the number of partitions where the difference between the sum of the left and right subarrays is even.


Example 1:
Input: nums = [10,10,3,7,6]
Output: 4
Explanation:

The 4 partitions are:

[10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
[10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
[10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
[10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.

Example 2:
Input: nums = [1,2,2]
Output: 0
Explanation:
No partition results in an even sum difference.

Example 3:
Input: nums = [2,4,6,8]
Output: 3
Explanation:
All partitions result in an even sum difference.

Constraints:

2 <= n == nums.length <= 100
1 <= nums[i] <= 100
*/

// solution :

class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> sumArr(n, 0);

        sumArr[0] = nums[0];

        for (int i = 1; i < n; i++)
            sumArr[i] = sumArr[i - 1] + nums[i];

        int totalSum = sumArr[n - 1];
        int count = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int lS = totalSum - sumArr[i];
            if ((sumArr[i] - lS) % 2 == 0)
                count++;
        }
        return count;
    }
};

/*
# Approach

### Step 1: Compute Prefix Sum Array
- Create a prefix sum array `sumArr`.
- `sumArr[i]` stores the sum of elements from index `0` to `i`.
- This allows us to find the left subarray sum in **O(1)** time.


### Step 2: Calculate the Total Sum
- The total sum of the array is the last element of the prefix sum array.
- `totalSum = sumArr[n - 1]`.

### Step 3: Check Every Possible Partition
- Iterate from index `0` to `n - 2` (since both subarrays must be non-empty).
- For each partition:
  - Left subarray sum = `sumArr[i]`
  - Right subarray sum = `totalSum - sumArr[i]`
- Compute the difference:
  - `leftSum - rightSum`
- If the difference is even (`% 2 == 0`), increment the count.

### Step 4: Return the Count
- After checking all possible partitions, return the total count of valid partitions.

# Time Complexity (TC)

- Building the prefix sum array: **O(n)**
- Traversing all possible partitions: **O(n)**

**Overall Time Complexity:** **O(n)**


# Space Complexity (SC)

- Prefix sum array stores `n` elements.

**Overall Space Complexity:** **O(n)**
*/