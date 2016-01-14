/*
    Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

    Link: http://www.lintcode.com/en/problem/subarray-sum-closest/

    Example: Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4].

    Solution: Use values and indexes in list to construct a two-dimenstional matrix, and sort values, use second to go back index information.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/subarray-sum-closest.cpp
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        const int n = nums.size();

        if (n == 1) {
            return {0, 0};
        }

        // sum_from_start[i] denotes sum for 0 ~ i - 1.
        vector<pair<int,int>> sum_from_start(n + 1, {0, 0});
        sum_from_start[0].second = -1; // For case closest sum is from 0.
        for (int i = 0; i < n; ++i) {
            sum_from_start[i + 1].first = sum_from_start[i].first + nums[i];
            sum_from_start[i + 1].second = i;
        }

        // Sort each sum from start.
        sort(sum_from_start.begin(), sum_from_start.end());

        int min_diff = INT_MAX;
        int start = -1;
        int end = -1;

        // Find min difference of adjacent sum.
        for (int i = 1; i <= n; ++i) {
            int diff = abs(sum_from_start[i].first - sum_from_start[i - 1].first);
            if (diff < min_diff) {
                min_diff = diff;
                start = min(sum_from_start[i].second, sum_from_start[i - 1].second) + 1;
                end = max(sum_from_start[i].second, sum_from_start[i - 1].second);
            }
        }

        return {start, end};
    }
};