// Topic : Hashing

/*
Question :
You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff.
A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:

i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.
Return the number of unique arithmetic triplets.



Example 1:

Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3.

Example 2:

Input: nums = [4,5,6,7,8,9], diff = 2
Output: 2
Explanation:
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.


Constraints:

3 <= nums.length <= 200
0 <= nums[i] <= 200
1 <= diff <= 50
nums is strictly increasing.
*/

// solution :

class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int n = nums.size();
        int count = 0;
        unordered_set<int> us;

        for (int i : nums)
            us.insert(i);

        for (int i : nums)
            if ((us.find(i + diff) != us.end()) && us.find(i - diff) != us.end())
                count++;

        return count;
    }
};

/*
# Approach

### Step 1: Store all elements in a Hash Set
- Create an `unordered_set`.
- Insert every element of `nums` into the hash set.
- This allows checking whether a number exists in **O(1)** average time.

### Step 2: Treat every element as the middle element
- Traverse the array.
- Consider the current element `num` as the **middle** of a possible arithmetic triplet.


### Step 3: Check for the left and right elements
- For the current element `num`, check whether:
  - `num - diff` exists in the hash set.
  - `num + diff` exists in the hash set.
- If both are present, then:
  - `(num - diff, num, num + diff)` forms a valid arithmetic triplet.
  - Increment the count.


### Step 4: Return the answer
- After checking every element, return the total count of arithmetic triplets.


# Time Complexity (TC)

- Inserting all elements into the hash set: **O(n)**
- Traversing the array and performing hash lookups: **O(n)**
- Each hash lookup takes **O(1)** on average.

**Overall Time Complexity:** **O(n)**


# Space Complexity (SC)

- The hash set stores all `n` elements.

**Overall Space Complexity:** **O(n)**
*/