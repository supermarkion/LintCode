/*
    Write a function that add two numbers A and B. You should not use + or any arithmetic operators.
    
    Link: http://www.lintcode.com/en/problem/a-b-problem/

    Example: Given a=1 and b=2 return 3

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/a-b-problem.cpp
*/

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        while (b != 0) {
            int carry = a & b;
            a ^= b;
            b = carry << 1;
        }
        return a;
    }
};