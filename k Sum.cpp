/*
    Given n distinct positive integers, integer k (k <= n) and a number target. Find k numbers where sum is target. 
    Calculate how many solutions there are?

    Link: http://www.lintcode.com/en/problem/k-sum/

    Example: Given [1,2,3,4], k = 2, target = 5. There are 2 solutions: [1,4] and [2,3]. Return 2.

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/k-sum.cpp
*/

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        const int n = A.size();

        // table[i][j][t] denotes the number of ways to select,
        // from first i elements, j elements whose sum equals to t
        vector<vector<vector<int>>> table(n+1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));

        for (int i = 1; i <= n; ++i) {
            if (A[i - 1] <= target)
            {
                for (int j = i; j <= n; ++j) {
                    table[j][1][A[i - 1]] = 1;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, k); j > 1; --j) {
                for (int p = 1; p <= target; ++p) {
                    table[i][j][p] = table[i - 1][j][p];
                    if (p - A[i - 1] >= 0) {
                        table[i][j][p] += table[i - 1][j - 1][p - A[i - 1]];
                    }
                }
            }
        }

        return table[n][k][target];
    }
};