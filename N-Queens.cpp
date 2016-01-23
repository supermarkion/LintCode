/*
    The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
	Given an integer n, return all distinct solutions to the n-queens puzzle. Each solution contains a distinct board 
	configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
    
    Link: http://www.lintcode.com/en/problem/n-queens/

    Example: There exist two distinct solutions to the 4-queens puzzle:
		[
		  // Solution 1
		  [".Q..",
		   "...Q",
		   "Q...",
		   "..Q."
		  ],
		  // Solution 2
		  ["..Q.",
		   "Q...",
		   "...Q",
		   ".Q.."
		  ]
		]

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/n-queens.cpp
*/

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<int> placement(n);
        vector<vector<string>> result;
        NQueensHelper(n, 0, &placement, &result);
        return result;
    }

    void NQueensHelper(int n, int row, vector<int>* col_placement,
                       vector<vector<string>>* result) {
        if (row == n) {
            result->emplace_back(CreateOutput(*col_placement));
        } else {
            for (int col = 0; col < n; ++col) {
                (*col_placement)[row] = col;
                if (IsFeasible(*col_placement, row)) {
                    NQueensHelper(n, row + 1, col_placement, result);
                }
            }
        }
    }

    vector<string> CreateOutput(const vector<int>& col_placement) {
        vector<string> sol;
        for (int row : col_placement) {
            string line(col_placement.size(), '.');
            line[row] = 'Q';
            sol.emplace_back(line);
        }
        return sol;
    }

    bool IsFeasible(const vector<int>& col_placement, int row) {
        for (int i = 0; i < row; ++i) {
            int diff = abs(col_placement[i] - col_placement[row]);
            if (diff == 0 || diff == row - i) {
                return false;
            }
        }
        return true;
    }
};
