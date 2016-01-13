/*
    Implement int sqrt(int x). Compute and return the square root of x.

    Link: http://www.lintcode.com/en/problem/sqrtx/

    Example: sqrt(3) = 1, sqrt(4) = 2, sqrt(5) = 2, sqrt(10) = 3.

    Solution: Perform newtown method to solve problem.

    Source: http://www.jiuzhang.com/solutions/sqrtx/
*/

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        // find the last number which square of it <= x
        long start = 1, end = x;
        while (start + 1 < end) {
            long mid = start + (end - start) / 2;
            if (mid * mid <= x) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (end * end <= x) {
            return (int) end;
        }
        return (int) start;
    }
};