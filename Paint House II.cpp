/*
    There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a 
    certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

	The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is 
	the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find 
	the minimum cost to paint all houses.
    
    Link: http://www.lintcode.com/en/problem/paint-house-ii/

    Example: 
	    Given n = 3, k = 3, costs = [[14,2,11],[11,14,5],[14,3,10]] return 10
		house 0 is color 2, house 1 is color 3, house 2 is color 2, 2 + 5 + 3 = 10
	
    Solution: None

    Source: http://www.cnblogs.com/easonliu/p/4784858.html
*/

class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        // Write your code here
        if (costs.empty() || costs[0].empty()) {
        	return 0;	
        }
        int n = costs.size(), k = costs[0].size();
        vector<int> min1(k), min2(k);
        for (int i = 1; i < costs.size(); ++i) {
            min1[0] = INT_MAX;
            for (int j = 1; j < k; ++j) {
                min1[j] = min(min1[j - 1], costs[i - 1][j - 1]);
            }
            min2[k-1] = INT_MAX;
            for (int j = k - 2; j >= 0; --j) {
                min2[j] = min(min2[j + 1], costs[i - 1][j + 1]);
            }
            for (int j = 0; j < k; ++j) {
                costs[i][j] += min(min1[j], min2[j]);
            }
        }
        int res = INT_MAX;
        for (auto c : costs.back()) {
            res = min(res, c);
        }
        return res;
    }
};