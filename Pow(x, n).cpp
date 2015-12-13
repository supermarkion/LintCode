/*
    Implement pow(x, n).
    Link: http://www.lintcode.com/en/problem/powx-n/
    Example: 
    Pow(2.1, 3) = 9.261
    Pow(0, 1) = 0
    Pow(1, 0) = 1
    You don't need to care about the precision of your answer, it's acceptable if the 
    expected answer and your answer 's difference is smaller than
    Solution: Divide n to two part, and recurse the function.
    Source: https://gist.github.com/luoxiaoxun/5882749
*/
class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if (n == 0) {
            return 1.0;
        }
        double half = myPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else if (n > 0) {
            return half * half * x;
        } else {
            return half * half / x;
        }
    }
};