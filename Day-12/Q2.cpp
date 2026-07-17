// Topic : Hashmap

/*
Question :
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.

*/

// solution :

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        unordered_map<int, int> frq;

        for (int i : nums)
        {
            frq[i]++;
        }

        for (auto i : frq)
        {
            if (i.second > (nums.size() / 2))
                return i.first;
        }

        return 0;
    }
};

// tc(n)

// sc:0(n)

/*
Apprach :

### Step 1:
Create an `unordered_map<int, int>` to store the frequency of each element.

### Step 2:
Traverse the array and increment the frequency of every element.

**Example:**

```text
nums = [2,2,1,1,1,2,2]

2 -> 4
1 -> 3
```

### Step 3:
Traverse the frequency map and check if any element has a frequency greater than `n / 2`.

- If `frequency > nums.size() / 2`, return that element.

Since the problem guarantees that a majority element always exists, the element satisfying the condition will always be found.

*/