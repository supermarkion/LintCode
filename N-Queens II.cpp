/*
    Follow up for N-Queens problem. Now, instead outputting board configurations, return the total number of distinct solutions.
    
    Link: http://www.lintcode.com/en/problem/n-queens-ii/

    Example: For n = 4, there are 2 distinct solutions.

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/n-queens-ii.cpp
*/

class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        vector<int> placement(n);
        return n_queens_helper(n, 0, &placement);
    }

    bool is_feasible(const vector<int>& col_placement, int row) {
        for (int i = 0; i < row; ++i) {
            int diff = abs(col_placement[i] - col_placement[row]);
            if (diff == 0 || diff == row - i) {
                return false;
            }
        }
        return true;
    }

    int n_queens_helper(int n, int row, vector<int>* col_placement) {
        if (row == n) {
            return 1;
        } else {
            int sum = 0;
            for (int col = 0; col < n; ++col) {
                (*col_placement)[row] = col;
                if (is_feasible(*col_placement, row)) {
                    sum += n_queens_helper(n, row + 1, col_placement);
                }
            }
            return sum;
        }
    }
};
