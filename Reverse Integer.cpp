/*
    Reverse digits of an integer. Returns 0 when the reversed integer overflows (signed 32-bit integer).
    Link: http://www.lintcode.com/en/problem/reverse-integer/
    Example:
        Given x = 123, return 321
        Given x = -123, return -321
    Solution: Remember to compare with INT_MAX and INT_MIN
    Source: https://github.com/kamyu104/LintCode/blob/master/C++/reverse-integer.cpp
*/

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        long long result = 0;
        unsigned int temp = abs(n);
        while (temp > 0) {
            result *= 10;
            result += temp % 10;
            temp /= 10;
        }
        result = (n >= 0) ? result : -result;
        result = (result > INT_MAX || result < INT_MIN) ? 0 : result;
        return result;
    }
};