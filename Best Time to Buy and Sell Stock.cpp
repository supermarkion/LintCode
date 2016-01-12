/*
    Say you have an array for which the ith element is the price of a given stock on day i.
	If you were only permitted to complete at most one transaction (ie, buy one and sell one 
	share of the stock), design an algorithm to find the maximum profit.

    Link: http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock/

    Example: Given an example [3,2,3,1,2], return 1

    Solution: If we only perform one purchase, then it is easy to know that we can get current 
    maximum and current minimum until end.

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
        if (prices.size() <= 1) {
            return 0;
        }
        int profit = 0;
        int curPriceMin = INT_MAX;
        for (const auto& price : prices) {
            profit = max(profit, price - curPriceMin);
            curPriceMin = min(curPriceMin, price);
        }
        return profit;
    }
};

