/*
    Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

    Link: http://www.lintcode.com/en/problem/set-matrix-zeroes/

    Example:
      Given a matrix
      [
        [1,2],
        [0,3]
      ],
      return
      [
        [0,2],
        [0,0]
      ]

    Solution: Use a flag to control whole process, and speed up computation.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/set-matrix-zeroes.cpp
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        if (matrix.empty()) {
            return;
        }
        bool has_zero = false;
        int zero_i = -1;
        int zero_j = -1;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    if (!has_zero) {
                        zero_i = i;
                        zero_j = j;
                        has_zero = true;
                    }
                    matrix[zero_i][j] = 0;
                    matrix[i][zero_j] = 0;
                }
            }
        }

        if (has_zero) {
            for (int i = 0; i < matrix.size(); ++i) {
                if (i == zero_i) {
                    continue;
                }
                for (int j = 0; j < matrix[0].size(); ++j) {
                    if (j == zero_j) {
                        continue;
                    }
                    if (matrix[zero_i][j] == 0 || matrix[i][zero_j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][zero_j] = 0;
            }
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[zero_i][j] = 0;
            }
        }

    }
};