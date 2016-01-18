/*
    Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

    Link: http://www.lintcode.com/en/problem/triangle/

    Example: For example, given the following triangle
		[
		     [2],
		    [3,4],
		   [6,5,7],
		  [4,1,8,3]
		]
		The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

    Solution: Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent
    numbers on the row below. We traversal the triangle from bottom to top, and make the value which located
    at index i and j only decided by the sum of values in i + 1, j and i + 1, j + 1.

    Source: None
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        if (triangle.empty()) {
            return 0;
        }
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int value = min(triangle[i + 1][j] + triangle[i][j],
                            triangle[i + 1][j + 1] + triangle[i][j]);
                triangle[i][j] = value;
            }
        }
        return triangle[0][0];
    }
};

