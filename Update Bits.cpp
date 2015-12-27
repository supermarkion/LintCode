/*
    Given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between 
    i and j in N equal to M (e g , M becomes a substring of N located at i and starting at j)

    Link: http://www.lintcode.com/en/problem/update-bits/

    Example: 
    	Given N=(10000000000)2, M=(10101)2, i=2, j=6
        return N=(10001010100)2

    Solution: First of all, construct a mask code, which have index i to index j are 0, and others are 1. After 
    get mask code, we move m with i digits, and use mask code to and original number n, then sum them to get result.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/update-bits.cpp
*/

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int right_part = n & ((1 << i) - 1);
        // The behavior of right shift >= 32 is undefined in C++.
        int left_part = j >= 31 ? 0 : (n >> (j + 1)) << (j + 1);
        return left_part | (m << i) | right_part;
    }
};