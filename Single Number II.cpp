/*
    Given 3*n + 1 numbers, every numbers occurs triple times except one, find it.

    Link: http://www.lintcode.com/en/problem/single-number-ii/

    Example: Given [1,1,2,3,3,3,2,2,4,1] return 4

    Solution: Given an array of integers, every element appears k times except for one. Find that single one which appears
    l times. We need a array x[i] with size k for saving the bits appears i times. For every input number a,
    generate the new counter by x[j] = (x[j − 1]&a)|(x[j]& a). Except x[0] = (x[k]&a)|(x[0]& a).

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/single-number-ii.cpp
*/

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int one = 0, two = 0;

        for (const auto& i : A) {
            int new_one = (~i & one) | (i & ~one & ~two);
            int new_two = (~i & two) | (i & one);
            one = new_one, two = new_two;
        }

        return one;
    }
};