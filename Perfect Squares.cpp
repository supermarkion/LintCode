/*
    Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
    
    Link: http://www.lintcode.com/en/problem/perfect-squares/

    Example: 
	    Given n = 12, return 3 because 12 = 4 + 4 + 4
		Given n = 13, return 2 because 13 = 4 + 9
	
    Solution: None

    Source: http://www.cnblogs.com/grandyang/p/4800552.html
*/

class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        while (n % 4 == 0) {				// reduce number size
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;			// postive int bool value is 0, and opposite is 1
            }
        }
        return 3;
    }
};