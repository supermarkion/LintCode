/*
    Follow up for "Unique Paths":
	Now consider if some obstacles are added to the grids. How many unique paths would there be?
	An obstacle and empty space is marked as 1 and 0 respectively in the grid.
    
    Link: http://www.lintcode.com/en/problem/unique-paths-ii/

    Example: 
	    There is one obstacle in the middle of a 3x3 grid as illustrated below.
		[
		  [0,0,0],
		  [0,1,0],
		  [0,0,0]
		]
		The total number of unique paths is 2.

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/unique-paths-ii.cpp
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();

        vector<vector<int>> path(2, vector<int>(n, 0));

        path[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int j = 1; j < n; ++j) {
            path[0][j] = obstacleGrid[0][j] == 0? path[0][j - 1] : 0;
        }

        for (int i = 1; i < m; ++i) {
            path[i % 2][0] = obstacleGrid[i][0] == 0? path[(i - 1) % 2][0] : 0;
            for (int j = 1; j < n; ++j) {
                path[i % 2][j] = obstacleGrid[i][j] == 0?
                path[(i - 1) % 2][j] + path[i % 2][j - 1] : 0;
            }
        }

        return path[(m - 1) % 2][n - 1];
    }
};