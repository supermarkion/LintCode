/*
    Given an array of integers and a number k, find k non-overlapping subarrays which have the largest sum. The number in 
    each subarray should be contiguous. Return the largest sum.
    
    Link: http://www.lintcode.com/en/problem/maximum-subarray-iii/

    Example: Given [-1,4,-2,3,-2,3], k=2, return 8

    Solution: Standard dynamic programming method, which construct a huge matrix, which saves all cost in sub-array
    maximum values. Then, we iteration sum first line, then move to move other cells.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/maximum-subarray-iii.cpp
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        const int n = nums.size();

        // sums[x][y] means the max sum in range [0, x - 1] with k non-overlapping subarrays
        vector<vector<int>> sums(n + 1, vector<int>(k + 1, INT_MIN));

        for (int i = 0; i <= n; ++i) {
            sums[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                sums[i][j] = sums[i - 1][j];
                int max_sum_from_p = 0;
                for (int p = i; p > j - 1; --p) {
                    max_sum_from_p = max(0, max_sum_from_p) + nums[p - 1];
                    // max sum in range[0, i - 1] with j subarrays equals to
                    // max sum in max(range [0, p - 2] with j - 1 subarrys plus
                    // max sum of the subarray which starts from p - 1 
                    sums[i][j] = max(sums[i][j], sums[p - 1][j - 1] + max_sum_from_p);
                }
            }
        }

        return sums[n][k];
    }
};
