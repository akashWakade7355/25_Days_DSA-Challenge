// Topic : Hashing

/*
Question :
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/

// solution :

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

      vector<int> ans;

      for(int i : nums1){
         for(int j=0;j<nums2.size();j++){
             if(nums2[j]==i){
                ans.push_back(i);
                nums2.erase(nums2.begin()+j);
                break;
             }
          }
        }
        return ans;
      }

};

/*
Apprach :

1. Create an Empty Result Array
   - Initialize a vector `ans` to store the common elements.

2. Traverse the First Array
   - Iterate through every element of `nums1`.

3. Search in the Second Array
   - For each element in `nums1`, traverse `nums2` to find a matching element.

4. Store the Common Element
   - If a match is found:
     - Add the element to the result vector `ans`.
     - Remove the matched element from `nums2` using `erase()` so that it cannot be matched again.
     - Break out of the inner loop to move to the next element in `nums1`.

5. Return the Result
   - After processing all elements, return the `ans` vector containing the intersection of the two arrays.

*/