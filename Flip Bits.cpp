/*
    Determine the number of bits required to flip if you want to convert integer n to integer m.
    Link: http://www.lintcode.com/en/problem/flip-bits/
    Example: Given n = 31 (11111), m = 14 (01110), return 2.
    Solution: Amzaing Bit Manual.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/flip-bits.cpp
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int cnt = 0;
        for (int c = a ^ b; c != 0; c &= c - 1) {
            ++cnt;
        }
        return cnt;
    }
};