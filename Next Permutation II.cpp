/*
    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
	If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
    Link: http://www.lintcode.com/en/problem/next-permutation-ii/
    Example: Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
		1,2,3 → 1,3,2
		3,2,1 → 1,2,3
		1,1,5 → 1,5,1
    Solution: In the problem on Permutation, the main process is to find the value which is greater or less than current
	digit, and then swap them. But this time, it is not enough, we should reverse the values from least values
	because we should get the maximum value following this digital. In the other word, we find a[k] < a[k + 1],
	then find a[k] < a[l], and swap k and l, and reverse k + 1 to end. For the previous part, it change to
	a[k] > a[k + 1] and a[k] > a[l].
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/next-permutation-ii.cpp
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        int k = -1, l = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                k = i;
            }
        }
        if (k >= 0) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > nums[k]) {
                    l = i;
                }
            }
            swap(nums[k], nums[l]);
        }
        reverse(nums.begin() + k + 1, nums.end());
    }
};