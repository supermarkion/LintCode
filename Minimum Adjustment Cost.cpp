/*
    Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than 
    a given number target. If the array before adjustment is A, the array after adjustment is B, you should minimize 
    the sum of |A[i]-B[i]|

    Link: http://www.lintcode.com/en/problem/minimum-adjustment-cost/

    Example: Given [1,4,2,3] and target = 1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and it's minimal.
	Return 2.

    Solution: It is a kind of backpack problem, and we should emulate all kinds of possible situation to find global 
    solution (because it assumes that all number in the array is positive and not greater than 100, we set second 
    dimensional size is 100).

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/minimum-adjustment-cost.cpp
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        const int n = A.size();
        const int max_num = 100;

        // min_cost[i][j] denotes the min cost of the first i elements
        // with target j.
        vector<vector<int>> min_cost(2, vector<int>(max_num + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= max_num; ++j) {
                // min_cost[i][j] = abs(A[i - 1] - j) +
                //                  min(min_cost[i][k],
                //                  for each k s.t. | k - j | <= target)
                int upper = min(max_num, j + target);
                int lower = max(1, j - target);
                min_cost[i % 2][j] = INT_MAX;
                for (int k = lower; k <= upper; ++k) {
                    min_cost[i % 2][j] = min(min_cost[i % 2][j],
                                             min_cost[(i - 1) % 2][k]);
                }
                min_cost[i % 2][j] += abs(A[i - 1] - j);
            }
        }

        // return min of min_cost[n] excluding min_cost[n][0]
        return *min_element(next(min_cost[n % 2].cbegin()), min_cost[n % 2].cend());
    }
};