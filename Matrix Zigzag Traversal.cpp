/*
    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in ZigZag-order.
    Link: http://www.lintcode.com/en/problem/matrix-zigzag-traversal/
    Example: Given a matrix:
		[
		  [1, 2,  3,  4],
		  [5, 6,  7,  8],
		  [9,10, 11, 12]
		]
		return [1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]
    Solution: located the correctly coordinates system in matrix.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/matrix-zigzag-traversal.cpp
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int>> &matrix) {
        vector<int> zigzag;
        const int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m + n - 1; ++i) {
            if (i % 2) {
                for (int y = min(i, n - 1);  y >= max(0, i - m + 1); --y) {
                    zigzag.emplace_back(matrix[i - y][y]);
                }
            } else {
                for (int x = min(i, m - 1);  x >= max(0, i - n + 1); --x) {
                    zigzag.emplace_back(matrix[x][i - x]);
                }
            }
        }

        return zigzag;
    }
};