/*
    Given a list of integers, which denote a permutation. Find the next permutation in ascending order.
    
    Link: http://www.lintcode.com/en/problem/next-permutation/

    Example: 
    	For [1,3,2,3], the next permutation is [1,3,3,2]
		For [4,3,2,1], the next permutation is [1,2,3,4]

    Solution: In the problem on Permutation, the main process is to find the value which is greater or less than current
	digit, and then swap them. But this time, it is not enough, we should reverse the values from least values
	because we should get the maximum value following this digital. In the other word, we find a[k] < a[k + 1],
	then find a[k] < a[l], and swap k and l, and reverse k + 1 to end. For the previous part, it change to
	a[k] > a[k + 1] and a[k] > a[l].

    Source: None
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.empty()) {
            return nums;
        }
        int len = nums.size();
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) {
                int j;
                for (j = len - 1; j > i - 1; j--) {
                    if (nums[j] > nums[i]) {
                        break;
                    }
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return nums;
            }
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};