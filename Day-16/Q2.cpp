// Topic : Carry Forward

/*
Question :

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

// solution :

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {

            minPrice = min(minPrice, prices[i]);

            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};

/*
# Approach

### Step 1:
Initialize two variables:
- `minPrice` with the first day's stock price.
- `maxProfit` as `0` since initially no profit has been made.

### Step 2:
Traverse the array from the second element to the last element.

### Step 3:
For each day's price, update `minPrice` by taking the minimum of the current `minPrice` and the current stock price. This ensures we always know the cheapest price seen so far for buying.

### Step 4:
Calculate the profit if the stock is sold on the current day:
- `currentProfit = prices[i] - minPrice`

Update `maxProfit` if `currentProfit` is greater than the current `maxProfit`.

### Step 5:
Continue this process until the end of the array.

### Step 6:
Return `maxProfit`. If no profitable transaction exists, `maxProfit` remains `0`.


# Time Complexity (TC)

- Single traversal of the array: **O(n)**

**Overall Time Complexity:** **O(n)**


# Space Complexity (SC)

- Only two extra variables (`minPrice` and `maxProfit`) are used.

**Overall Space Complexity:** **O(1)**
*/