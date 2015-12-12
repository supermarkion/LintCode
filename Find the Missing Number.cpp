/*
    Given an array contains N numbers of 0 .. N, find which number doesn't exist in the array.
    Link: http://www.lintcode.com/en/problem/find-the-missing-number/
    Example: Given N = 3 and the array [0, 1, 3], return 2.
    Solution: We use the XOR operation's defintion, we can use XOR to compute 'sum' of expected list,
    and then use this 'sum' to perform XOR again, to delete duplicate number, and get missing value.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/find-the-missing-number.cpp
*/

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int missing_num = 0;
        // perform xor operation to find mising value
        for (int num = 0; num <= nums.size(); num++) {
            missing_num ^= num;
        }
        // then, we perform xor again to delete repeat number
        for (const auto& num : nums) {
            missing_num ^= num;
        }
        return missing_num;
    }
};