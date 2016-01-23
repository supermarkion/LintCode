/*
    Given an array of integers, find two non-overlapping subarrays which have the largest sum. The number in each subarray 
    should be contiguous. Return the largest sum.
    
    Link: http://www.lintcode.com/en/problem/maximum-subarray-ii/

    Example: For given [1, 3, -1, 2, -1, 2], the two subarrays are [1, 3] and [2, -1, 2] or [1, 3, -1, 2] and [2], they 
    both have the largest sum 7.

    Solution: In this problem, we should get the max value from left to right, and right to left. Then, we add two elements
    form two lists, and get the max values.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/maximum-subarray-ii.cpp
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        vector<int> max_LR(n);
        vector<int> max_RL(n);

        // Compute the max sum of subarray from left to right.
        int max_LR_sum = INT_MIN, LR_sum = 0;
        for (int i = 0; i < n; ++i) {
            LR_sum += nums[i];
            max_LR_sum = max(max_LR_sum, LR_sum);
            max_LR[i] = max_LR_sum;
            LR_sum = max(LR_sum, 0);
        }

        // Compute the max sum of subarray from right to left.
        int max_RL_sum = INT_MIN, RL_sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            RL_sum += nums[i];
            max_RL_sum = max(max_RL_sum, RL_sum);
            max_RL[i] = max_RL_sum;
            RL_sum = max(RL_sum, 0);
        }

        // Compute the max sum of two non-overlapping subarrays.
        int max_sum = INT_MIN;
        for (int i = 0; i < n - 1; ++i) {
            max_sum = max(max_sum, max_LR[i] + max_RL[i + 1]);
        }

        return max_sum;
    }
};