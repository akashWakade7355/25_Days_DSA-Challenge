// Tpoic : Hashmap

/*
Question :
Given two arrays a[] and b[], your task is to determine whether b[] is a subset of a[].

Examples:

Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
Output: true
Explanation: b[] is a subset of a[]
Input: a[] = [1, 2, 3, 4, 4, 5, 6], b[] = [1, 2, 4]
Output: true
Explanation: b[] is a subset of a[]
Input: a[] = [10, 5, 2, 23, 19], b[] = [19, 5, 3]
Output: false
Explanation: b[] is not a subset of a[]

Constraints:
1 <= a.size(), b.size() <= 105
1 <= a[i], b[j] <= 106
*/ 

//solution 

class Solution {
public:
    bool isSubset(vector<int> &a, vector<int> &b) {

        if (b.size() > a.size())
            return false;

        unordered_map<int, int> freq;

        for (int num : a) {
            freq[num]++;
        }

        for (int num : b) {
            if (freq[num] == 0)
                return false;

            freq[num]--;
        }

        return true;
    }
};

/*Time Complexity:
- Building the frequency map: O(n)
- Checking all elements of b: O(m)
- Overall: O(n + m)
*/

// SC:0(a.size())

/*
Approach:

1. Since a subset cannot have more elements than the original array,
   first compare the sizes of both arrays.
   - If b.size() > a.size(), return false immediately.

2. Create an unordered_map<int, int> named "freq" to store the
   frequency of every element present in array 'a'.

   Example:
   a = [11, 7, 1, 13, 21, 3, 7, 3]

   Frequency Map:
   11 -> 1
   7  -> 2
   1  -> 1
   13 -> 1
   21 -> 1
   3  -> 2

3. Traverse array 'b' one element at a time.
   For every element:
   - If its frequency in the map is 0, it means either:
       • the element does not exist in 'a', or
       • all its occurrences have already been used.
     Hence, return false.
   - Otherwise, decrement its frequency by 1 to mark one occurrence
     as used.

4. If all elements of array 'b' are successfully found with the
   required frequency, return true because 'b' is a subset of 'a'.

Why use a HashMap?
- It allows us to store and access the frequency of each element in
  O(1) average time.
- It also correctly handles duplicate elements, unlike an unordered_set,
  which only stores unique values.


*/