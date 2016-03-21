/*
    There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. 
    The cost of painting each house with a certain color is different. You have to paint all the houses such 
    that no two adjacent houses have the same color.

	The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, 
	costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 
	with color green, and so on... Find the minimum cost to paint all houses.
    
    Link: http://www.lintcode.com/en/problem/paint-house/

    Example: 
    	Given costs = [[14,2,11],[11,14,5],[14,3,10]] return 10
		house 0 is blue, house 1 is green, house 2 is blue, 2 + 5 + 3 = 10

    Solution: None

    Source: http://www.cnblogs.com/jcliBlogger/p/4729957.html
*/

class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        if (costs.empty()) {
            return 0;   
        }
        int n = costs.size(), r = 0, g = 0, b = 0;
        for (int i = 0; i < n; i++) {
            int rr = r, bb = b, gg = g; 
            r = costs[i][0] + min(bb, gg);
            b = costs[i][1] + min(rr, gg);
            g = costs[i][2] + min(rr, bb);
        }
        return min(r, min(b, g));
    }
};