/*
    Given an array of integers, find the subarray with smallest sum. Return the sum of the subarray.
    
    Link: http://www.lintcode.com/en/problem/minimum-subarray/

    Example: For [1, -1, -2, 1], return -3

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/minimum-subarray.cpp
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int min_sum = INT_MAX, sum = 0;
        for (const auto& num : nums) {
            sum += num;
            min_sum = min(min_sum, sum);
            if (sum > 0) {
                sum = 0;
            }
        }
        return min_sum;
    }
};
