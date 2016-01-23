/*
    Given a list of integers, which denote a permutation. Find the previous permutation in ascending order.
    
    Link: http://www.lintcode.com/en/problem/previous-permutation/

    Example: 
        For [1,3,2,3], the previous permutation is [1,2,3,3]
        For [1,2,3,4], the previous permutation is [4,3,2,1]

    Solution: In the problem on Permutation, the main process is to find the value which is greater or less than current
	digit, and then swap them. But this time, it is not enough, we should reverse the values from least values
	because we should get the maximum value following this digital. In the other word, we find a[k] < a[k + 1],
	then find a[k] < a[l], and swap k and l, and reverse k + 1 to end. For the previous part, it change to
	a[k] > a[k + 1] and a[k] > a[l].

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/previous-permutation.cpp
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int k = -1, l = 0;

        // Find the last index k before the increasing sequence.
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                k = i;
            }
        }

        if (k >= 0) {
            // Find the largest number which is smaller than the value of the index k,
            // and swap the values.
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < nums[k]) {
                    l = i;
                }
            }
            swap(nums[k], nums[l]);
        }

        // Reverse the sequence after the index k.
        reverse(nums.begin() + k + 1, nums.end());

        return nums;
    }
};