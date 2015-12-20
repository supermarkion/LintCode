/*
    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
    Link: http://www.lintcode.com/en/problem/spiral-matrix/
    Example: Given the following matrix:
		[
		 [ 1, 2, 3 ],
		 [ 4, 5, 6 ],
		 [ 7, 8, 9 ]
		]
		You should return [1,2,3,6,9,8,7,4,5].
    Solution: Around the 'cycle' to construct this matrix, but take the reverse order of problem two.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/spiral-matrix.cpp
*/

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }

        for (int left = 0, right = matrix[0].size() - 1,
                 top = 0, bottom = matrix.size() - 1;
             left <= right && top <= bottom;
             ++left, --right, ++top, --bottom) {

            for (int j = left; j <= right; ++j) {
                res.emplace_back(matrix[top][j]);
            }
            for (int i = top + 1; i < bottom; ++i) {
                res.emplace_back(matrix[i][right]);
            }
            for (int j = right; top < bottom && j >= left; --j) {
                res.emplace_back(matrix[bottom][j]);
            }
            for (int i = bottom - 1; left < right && i > top; --i) {
                res.emplace_back(matrix[i][left]);
            }
        }

        return res;
    }
};