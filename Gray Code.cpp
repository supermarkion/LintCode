/*
    The gray code is a binary numeral system where two successive values differ in only one bit.
	Given a non-negative integer n representing the total number of bits in the code, find the sequence of 
	gray code. A gray code sequence must begin with 0 and with cover all 2n integers.
    Link: http://www.lintcode.com/en/problem/gray-code/
    Example: Given n = 2, return [0,1,3,2]. Its gray code sequence is:
        00 - 0
		01 - 1
		11 - 3
		10 - 2
    Solution: It based on move and or operations.
    Source: 
    	https://en.wikipedia.org/wiki/Gray_code
*/

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> currGray;
        if (n < 0) {
            return currGray;
        }
        currGray.emplace_back(0);
        for (int i = 0; i < n; i++) {
            int msb = 1 << i;
            for (int j = currGray.size() - 1; j >= 0; j--) {
                currGray.emplace_back(msb | currGray[j]);
            }
        }
        return currGray;
    }
};