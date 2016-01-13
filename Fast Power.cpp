/*
    Calculate the an % b where a, b and n are all 32bit integers.

    Link: http://www.lintcode.com/en/problem/fast-power/

    Example: 
    	For 2^{31} % 3 = 2
		For 100^{1000} % 1000 = 0

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/fast-power.cpp
*/

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        return longFastPower(a % b, b, n);
    }

    long long longFastPower(long long a, int b, int n) {
        if (n == 0) {
            return 1 % b;
        }
        if (n % 2 == 1) {
            return (a * longFastPower((a * a) % b, b, n / 2)) % b;
        } else {
            return longFastPower((a * a) % b, b, n / 2);
        }
    }
};