/*
    Partition an integers array into odd number first and even number second.
    Link: http://www.lintcode.com/en/problem/partition-array-by-odd-and-even/
    Example: Given [1, 2, 3, 4], return [1, 3, 2, 4]

    Solution: The partition process (from quicksort algorithm), it applies two pointers, 
    and exchange the values of two values. However, in the full version of quick sort, 
    it use pivot as the target value, but this problem, we only use k as pivot and divided 
    array into two parts.

    Source: None
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        if (nums.empty()) {
            return;
        }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            while (l <= r && nums[l] % 2 == 1) {
                l++;
            }
            while (l <= r && nums[r] % 2 == 0) {
                r--;
            }
            if (l < r) {
                swap(nums[l++], nums[r--]);
            }
        }
    }
};