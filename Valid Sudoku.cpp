/*
    Determine whether a Sudoku is valid. The Sudoku board could be partially filled, where empty cells are filled with the character.
    Link: http://www.lintcode.com/en/problem/valid-sudoku/
    Example: None
    Solution: In this problem, in order to speed up the process on calculate the number in char matrix is unique, we use the char 
    minus ’1’ to get the distance in ASCII code, and use it as index of a list, then if it already exits this number, it boolean 
    result should be true, and then return false.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/valid-sudoku.cpp
*/

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        // Check row constraints.
        for (int i = 0; i < board.size(); ++i) {
            if (HasDuplicate(board, i, i + 1, 0, board.size(), board.size())) {
                return false;
            }
        }

        // Check column constraints.
        for (int j = 0; j < board.size(); ++j) {
            if (HasDuplicate(board, 0, board.size(), j, j + 1, board.size())) {
                return false;
            }
        }

        // Check region constraints.
        int region_size = sqrt(board.size());
        for (int i = 0; i < region_size; ++i) {
            for (int j = 0; j < region_size; ++j) {
                if (HasDuplicate(board, region_size * i, region_size * (i + 1),
                                 region_size * j, region_size * (j + 1), board.size())) {
                    return false;
                }
            }
        }
        return true;
    }

    // Return true if subarray board[start_row : end_row - 1][start_col : end_col - 1]
    // contains any duplicates in [1 : num_elements]; otherwise return false.
    bool HasDuplicate(const vector<vector<char>>& board, int start_row, int end_row,
                      int start_col, int end_col, int num_elements) {
        deque<bool> is_present(num_elements + 1, false);
        for (int i = start_row; i < end_row; ++i) {
            for (int j = start_col; j < end_col; ++j) {
                if (board[i][j] != '.' && is_present[board[i][j] - '0']) {
                    return true;
                }
                is_present[board[i][j] - '0'] = true;
            }
        }
        return false;
    }
};