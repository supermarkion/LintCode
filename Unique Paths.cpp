/*
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
	The robot can only move either down or right at any point in time. The robot is trying to reach 
	the bottom-right corner of the grid (marked 'Finish' in the diagram below). How many possible 
	unique paths are there?
    
    Link: http://www.lintcode.com/en/problem/unique-paths/

    Example: 
	    1,1 	1,2 	1,3 	1,4 	1,5 	1,6 	1,7
		2,1	
		3,1												3,7

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/unique-paths.cpp
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        return combination(m + n - 2, min(m - 1, n - 1));
    }

    int combination(int  n, int k) {
        long long count = 1;
        // C(n, k) = (n) / 1 * (n - 1) / 2 ... * (n - k + 1) / k
        for (int i = 1; i <= k; ++i, --n) {
            count = count * n / i;
        }

        return count;
    }
};
