/*
    You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).

    Link: http://www.lintcode.com/en/problem/rotate-image/

    Example:
      Given a matrix
      [
        [1,2],
        [3,4]
      ]
      rotate it by 90 degrees (clockwise), return
      [
        [3,1],
        [4,2]
      ]

    Solution: perform two times swap to finish rotate.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/rotate-image.cpp
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        const int n = matrix.size();
        // Anti-diagonal mirror.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        // Horizontal mirror.
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};