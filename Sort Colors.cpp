/*
    Given an array with n objects colored red, white or blue, sort them so that objects of the same color are 
    adjacent, with the colors in the order red, white and blue. Here, we will use the integers 0, 1, and 2 to 
    represent the color red, white, and blue respectively.

    Link: http://www.lintcode.com/en/problem/sort-colors/

    Example: Given [1, 0, 1, 2], return [0, 1, 1, 2].

    Solution: n the three color flag problem, we use a index to loop the list, once we meet the zero, put it at 
    the left, meet the two, put it at right, meet one, continue.

    Source: None
*/

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        if (nums.empty() || nums.size() < 2) {
            return;
        }
        int left = 0;
        int right = nums.size() - 1;
        int i = 0;
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[left], nums[i]);
                left++;
                i++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[right], nums[i]);
                right--;
            }
        }
    }
    
};