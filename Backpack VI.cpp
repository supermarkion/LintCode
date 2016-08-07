/*
    Given an integer array nums with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

    Link: http://www.lintcode.com/en/problem/backpack-vi/

    Example: 
    	Given nums = [1, 2, 4], target = 4
		The possible combination ways are:
		[1, 1, 1, 1]
		[1, 1, 2]
		[1, 2, 1]
		[2, 1, 1]
		[2, 2]
		[4]
		return 6

    Solution: None

    Source: http://www.jiuzhang.com/solutions/backpack-vi/
*/

class Solution {
public:
    /**
     * @param nums an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    int backPackVI(vector<int>& nums, int target) {
        // Write your code here
        vector<int> dp(target + 1);
        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i) 
        {
            for (auto a : nums)
            {
            	if (i >= a) 
            	{
                	dp[i] += dp[i - a];
            	}
            }
            
        }
        return dp.back();
    }
};