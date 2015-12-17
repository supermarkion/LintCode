/*
    Say you have an array for which the ith element is the price of a given stock on day i.
    Design an algorithm to find the maximum profit. You may complete at most k transactions.
    Link: http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock-iv/
    Example: Given prices = [4,4,6,1,1,4,2,5], and k = 2, return 6.
    Solution: For the part four, if the quantity of transaction is big enough, it can change to part 
    two problem. Or we will apply dynamic programming to solve it.
    Source: http://www.jiuzhang.com/solutions/best-time-to-buy-and-sell-stock-iv/
*/

class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        if (prices.empty()) 
            return 0;
        int ans = 0;
        if (k >= prices.size())
        {
            
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i - 1] > 0) {
                    ans += prices[i] - prices[i - 1];
                }
            }
        } else {

            
            vector<int> local(k+1);
            vector<int> global(k+1);
            
            for (int i = 0; i < prices.size() - 1; ++i) {
                int increase = prices[i + 1] - prices[i];
    
                for (int j = k; j >= 1; --j) {
                    local[j] = max(global[j - 1] + max(increase, 0), local[j] + increase);
                    global[j] = max(global[j], local[j]);
                }
            }
            ans = global[k];
        }
        return ans;
    }
};