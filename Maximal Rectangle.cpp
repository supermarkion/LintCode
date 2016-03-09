/*
    Given a 2D boolean matrix filled with False and True, find the largest rectangle containing all True and return its area.
    
    Link: http://www.lintcode.com/en/problem/maximal-rectangle/

    Example: Given a matrix:
		[
		  [1, 1, 0, 0, 1],
		  [0, 1, 0, 0, 1],
		  [0, 0, 1, 1, 1],
		  [0, 0, 1, 1, 1],
		  [0, 0, 0, 0, 1]
		]
		return 6.

    Solution: None

    Source: https://leetcode.com/discuss/86324/sharing-my-12ms-c-solution
*/

class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    int maximalRectangle(vector<vector<bool> > &matrix) {
        // Write your code here
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
            
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
            
        int result = 0;
        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n - 1);
        int currentLeft, currentRight;
        int i, j;
        for (i = 0; i < m; i++) {
            currentLeft = 0;
            currentRight = n - 1;
            for (j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }

            for (j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    left[j] = max(left[j], currentLeft);
                } else {
                    left[j] = 0;
                    currentLeft = j + 1;
                }
            }

            for (j = n-1; j >= 0; j--) {
                if (matrix[i][j]) {
                    right[j] = min(right[j], currentRight);
                } else {
                    right[j] = n - 1;
                    currentRight = j - 1;
                }
            }

            for (j = 0; j < n; j++)
                result = max(result, (right[j] - left[j] + 1) * height[j]);
        }

        return result;
    }
};