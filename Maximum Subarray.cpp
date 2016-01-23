/*
    Given an array of integers, find a contiguous subarray which has the largest sum.
    
    Link: http://www.lintcode.com/en/problem/maximum-subarray/

    Example: Given the array [−2, 2, −3, 4, −1, 2, 1, −5, 3], the contiguous subarray [4, −1, 2, 1] has the largest sum = 6.

    Solution: Given an array of integers, find a contiguous sub-array which has the largest sum. In this problem, the main
    point is how to skip tiny minus, and achieve highest goal. Then, we use one variable named maxEnd, to make the tiny 
    minus will not effect on the current highest goal, and make it possible to get more scare in the following indexes.
    
    Source: None
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int maxHere = nums[0], maxEnd = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxHere = max(nums[i], maxHere + nums[i]);
            maxEnd = max(maxHere, maxEnd);
        }
        return maxEnd;
    }
};
