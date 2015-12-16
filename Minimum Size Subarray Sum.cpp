/*
    Given an array of n positive integers and a positive integer s, find the minimal
    length of a subarray of which the sum ≥ s. If there isn't one, return -1 instead.
    Link: http://www.lintcode.com/en/problem/minimum-size-subarray-sum/
    Example: Given the array [2,3,1,2,4,3] and s = 7, the subarray [4,3] has the minimal
    length under the problem constraint.
    Solution: Given an array of n positive integers and a positive integer s, find the minimal 
    length of a subarray of which the sum greater or equal to s. Then, we can use two pointers
    to perform add or minus number to sum. Once the current sum is smaller than target number, 
    we add one from new number at right. When current sum is greater than target, we minus one 
    number from old number at left. Moreover, our task is to find the minimum size of subarray 
    which sum is equal to target number, we should also save the minimum length by use right to 
    minus left.
    Source: None
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        if (nums.empty()) {
            return -1;
        }
        int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
        while (right < len) {
            while (sum < s && right < len) {
                sum += nums[right];
                right++;
            }
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return res == len + 1 ? -1 : res;
    }
};