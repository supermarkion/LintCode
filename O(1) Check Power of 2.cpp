/*
    Using O(1) time to check whether an integer n is a power of 2.

    Link: http://www.lintcode.com/en/problem/o1-check-power-of-2/

    Example: 
        For n=4, return true;
        For n=5, return false;

    Solution: Check the last digit is 1 or not in binary style.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/o1-check-power-of-2.cpp
*/

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        return n > 0 && (n & (n - 1)) == 0;
    }
};