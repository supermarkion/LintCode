/*
    Given an array with integers. Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest. 
    Return the largest difference.
    
    Link: http://www.lintcode.com/en/problem/maximum-subarray-difference/

    Example: For [1, 2, -3, 1], return 6.

    Solution: In this problem, the dp list used to save the current previous and post index min and max values, then use
    these max and min value list to get the maximum difference.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/maximum-subarray-difference.cpp
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        vector<int> max_LR(n), min_LR(n);
        vector<int> max_RL(n), min_RL(n);

        // Compute the max sum of subarray from left to right.
        int max_LR_sum = INT_MIN, LR_sum = 0;
        for (int i = 0; i < n; ++i) {
            LR_sum += nums[i];
            max_LR_sum = max(max_LR_sum, LR_sum);
            max_LR[i] = max_LR_sum;
            if (LR_sum < 0) {
                LR_sum = 0;
            }
        }

        // Compute the min sum of subarray from left to right.
        int min_LR_sum = INT_MAX;
        LR_sum = 0;
        for (int i = 0; i < n; ++i) {
            LR_sum += nums[i];
            min_LR_sum = min(min_LR_sum, LR_sum);
            min_LR[i] = min_LR_sum;
            if (LR_sum > 0) {
                LR_sum = 0;
            }
        }

        // Compute the max sum of subarray from right to left.
        int max_RL_sum = INT_MIN, RL_sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            RL_sum += nums[i];
            max_RL_sum = max(max_RL_sum, RL_sum);
            max_RL[i] = max_RL_sum;
            if (RL_sum < 0) {
                RL_sum = 0;
            }
        }

        // Compute the min sum of subarray from right to left.
        int min_RL_sum = INT_MAX;
        RL_sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            RL_sum += nums[i];
            min_RL_sum = min(min_RL_sum, RL_sum);
            min_RL[i] = min_RL_sum;
            if (RL_sum > 0) {
                RL_sum = 0;
            }
        }

        // Compute the max diff of two non-overlapping subarrays.
        int max_diff = 0;
        for (int i = 0; i < n - 1; ++i) {
            max_diff = max(max_diff, abs(max_LR[i] - min_RL[i + 1]));
            max_diff = max(max_diff, abs(min_LR[i] - max_RL[i + 1]));
        }

        return max_diff;
    }
};
