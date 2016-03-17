/*
    Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
    You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] 
    coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

	Find the maximum coins you can collect by bursting the balloons wisely.
	- You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
	- 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
    
    Link: http://www.lintcode.com/en/problem/burst-balloons/

    Example: Given [4, 1, 5, 10]
		Return 270

	nums = [4, 1, 5, 10] burst 1, get coins 4 * 1 * 5 = 20
	nums = [4, 5, 10]    burst 5, get coins 4 * 5 * 10 = 200 
	nums = [4, 10]       burst 4, get coins 1 * 4 * 10 = 40
	nums = [10]          burst 10, get coins 1 * 10 * 1 = 10

	Total coins 20 + 200 + 40 + 10 = 270
	
    Solution: None

    Source: None
*/

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return an integer, maximum coins
     */  
    int maxCoins(vector<int>& nums) {
        // Write your code here
        int n = nums.size();
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);
		vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n - k + 1; i++) {
				int j = i + k - 1;
				for (int x = i; x <= j; x++) {
					int temp = dp[i][x - 1] + nums[i - 1] * nums[x] * nums[j + 1] + dp[x + 1][j];
					if (dp[i][j] < temp) {
					    dp[i][j] = temp;
					}
				}
			}
		}
		return dp[1][n];
    }
};
