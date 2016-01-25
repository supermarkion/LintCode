/*
    Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:
		All elements < k are moved to the left
		All elements >= k are moved to the right
		Return the partitioning index, i.e the first index i nums[i] >= k.
    
    Link: http://www.lintcode.com/en/problem/partition-array/

    Example: If nums = [3,2,2,1] and k=2, a valid answer is 1.

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/partition-array.cpp
*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int left = 0;
        int right = nums.size();

        while (left < right) {
            if (nums[left] < k) {  // Increase left boundary.
                ++left;
            } else {  // Put every element > k to the right.
                swap(nums[left], nums[--right]);
            }
        }

        return left;
    }
};