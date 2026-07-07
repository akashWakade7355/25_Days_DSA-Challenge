// Topic : Hashmap 

/*
Question :
Given an array arr[] of integers. Write a program to check whether an arithmetic progression can be formed using all the given elements. 

Examples:

Input: arr[] = [0, 12, 4, 8]
Output: true
Explanation: Rearrange given array as [0, 4, 8, 12] which forms an arithmetic progression.
Input: arr[] = [12, 40, 11, 20]
Output: false
Explanation: there is no rearrangment which can forms an arithmetic progression.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
*/

// solution 

class Solution {
  public:
    bool checkIsAP(vector<int> &arr) {
        // Your code goes here
        
        sort(arr.begin(),arr.end());
        int d=arr[1]-arr[0];
        int n=arr.size();
        for(int i=2;i<n;i++)
        {
            if(arr[i]-arr[i-1]!=d)
            {
                return false;
            }
        }
        
        return true;
    }
};

// TC:0(n)

// SC:0(1)

/*
Approach:

1. Sort the given array in ascending order.
   - If the elements can form an Arithmetic Progression (AP),
     then after sorting, every pair of consecutive elements
     must have the same common difference.

2. Calculate the common difference 'd' using the first two elements.
   - d = arr[1] - arr[0]

3. Traverse the remaining elements of the sorted array.
   - For every index i (starting from 2), calculate the difference
     between the current element and its previous element.
   - If this difference is not equal to 'd', it means the sequence
     cannot form an Arithmetic Progression, so return false.

4. If all consecutive differences are equal to 'd',
   then every element follows the same common difference.
   Hence, the given array can be rearranged to form an
   Arithmetic Progression. Return true.


*/