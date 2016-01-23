/*
    Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it. This matrix 
    has the following properties:
		Integers in each row are sorted from left to right.
		Integers in each column are sorted from up to bottom.
		No duplicate integers in each row or column.
    
    Link: http://www.lintcode.com/en/problem/search-a-2d-matrix-ii/

    Example: Consider the following matrix:
		[
		  [1, 3, 5, 7],
		  [2, 4, 7, 8],
		  [3, 5, 9, 10]
		]
		Given target = 3, return 2.

    Solution: In this problem, we should use a pointer to move through matrix based its definition. However, we should
    also consider of situation that not stuck in first line, not raise error at edge.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/search-a-2d-matrix-ii.cpp
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
         const int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        const int n = matrix[0].size();
        if  (n == 0) {
            return 0;
        }
        int count = 0;

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                ++count;
                ++i;
                --j;
            } else if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }

        return count;
    }
};
