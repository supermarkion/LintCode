/*
    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
		Integers in each row are sorted from left to right.
		The first integer of each row is greater than the last integer of the previous row.
    
    Link: http://www.lintcode.com/en/problem/search-a-2d-matrix/

    Example: Consider the following matrix:
		[
		    [1, 3, 5, 7],
		    [10, 11, 16, 20],
		    [23, 30, 34, 50]
		]
		Given target = 3, return true.

    Solution: In this problem, we should use a pointer to move through matrix based its definition. However, we should
    also consider of situation that not stuck in first line, not raise error at edge.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/search-a-2d-matrix.cpp
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.empty()) {
            return false;
        }

        // Treat matrix as 1D array.
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left = -1;
        int right = m * n;

        // Find min of right s.t.  matrix[right / n][right % n] >= target
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / n][mid % n] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }

        // Check if matrix[right / n][right % n] equals to target.
        if (right != m * n && matrix[right / n][right % n] == target) {
            return true;
        }

        return false;
    }
};
