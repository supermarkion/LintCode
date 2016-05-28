/*
    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Link: http://www.lintcode.com/en/problem/move-zeroes/

    Example: 
    	Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

    Solution: None

    Source: None
*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};