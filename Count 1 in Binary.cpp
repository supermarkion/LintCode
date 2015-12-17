/*
    Count how many 1 in binary representation of a 32-bit integer.
    Link: http://www.lintcode.com/en/problem/count-1-in-binary/
    Example: 
	    Given 32, return 1
		Given 5, return 2
		Given 1023, return 9
    Solution: Perform & operation to get 1 in a number.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/count-1-in-binary.cpp
*/

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int count = 0;
        for (; num; num &= num - 1) {
            ++count;
        }
        return count;
    }
};