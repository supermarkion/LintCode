/*
    Give you an integer matrix (with row size n, column size m)，find the longest increasing continuous subsequence 
    in this matrix. (The definition of the longest increasing continuous subsequence here can start at any row or 
    column and go up/down/right/left any direction).
    
    Link: http://www.lintcode.com/en/problem/longest-increasing-continuous-subsequence-ii/
    
    Example: Given a matrix:
        [
          [1 ,2 ,3 ,4 ,5],
          [16,17,24,23,6],
          [15,18,25,22,7],
          [14,19,20,21,8],
          [13,12,11,10,9]
        ]
        return 25
    Solution: four directs to construct fill function.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/longest-increasing-continuous-subsequence-ii.cpp
*/

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        if (A.empty()) {
            return 0;
        }

        // max_inc_len[i][j] stores the length of longest increasing continuous 
        // subsequence which starts with A[i][j]
        vector<vector<int>> max_inc_len(A.size(), vector<int>(A[0].size(), 0));
        int ans = 0;

        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                // Not yet visited.
                if (max_inc_len[i][j] == 0) {
                    ans = max(ans, fill(A, i, j, INT_MIN, max_inc_len));
                }
            }
        }

        return ans;
    }

    int fill(const vector<vector<int>>& A, const int i, const int j,
             const int prev_val,
             vector<vector<int>>& max_inc_len) {
        // Invalid cases.
        if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() ||
            A[i][j] <= prev_val) {
            return 0;
        }

        // Return max_inc_len if visited.
        if (max_inc_len[i][j] > 0) {
            return max_inc_len[i][j];
        }

        // Try each direction to find the max of max_inc_len[i][j].
        const vector<pair<int, int>> directions = {{0, 1}, {0, -1},
                                                   {1, 0}, {-1, 0}};
        for (const auto& d : directions) {
            max_inc_len[i][j] = max(max_inc_len[i][j],
                                    1 + fill(A, i + d.first, j + d.second,
                                             A[i][j], max_inc_len));
        }

        return max_inc_len[i][j];
    }
};