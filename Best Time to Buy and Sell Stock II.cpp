/*
    Say you have an array for which the ith element is the price of a given stock on day i.
	Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
	(ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple 
	transactions at the same time (ie, you must sell the stock before you buy again).

    Link: http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock-ii/

    Example: Given an example [2,1,2,0,1], return 2

    Solution: we can buy as much times as possible as we want, then we gen get all profit between two peak and gap

    Source: None
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.empty() && prices.size() == 1) {
            return 0;
        }
        int profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) {
                profit += diff;
            }
        }
        
        return profit;
    }
};