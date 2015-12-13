/*
    Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 
    1's and return its area.
    Link: http://www.lintcode.com/en/problem/maximal-square/
    Example: For example, given the following matrix:
    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0
    Solution: The main point is that we assign the dp matrix with the minimum of surrounding values, 
    The changing condition is:
        dp[i][j] = min(t[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1. It means the square formed before this point.
    Source: 
        http://www.programcreek.com/2014/06/leetcode-maximal-square-java/
        https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/maximal-square.cpp
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        int max_size = 0;

        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
            max_size = max(max_size, dp[0][j]);
        }
        for (int i = 1; i < m; ++i) {
            dp[i % 2][0] = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    dp[i % 2][j] = min(dp[i % 2][j - 1], 
                                         min(dp[(i - 1) % 2][j], 
                                             dp[(i - 1) % 2][j - 1])) + 1;
                    max_size = max(max_size, dp[i % 2][j]);
                } else {
                    dp[i % 2][j] = 0;
                }
            }
        }
        return max_size * max_size;
    }
};