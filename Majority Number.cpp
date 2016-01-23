/*
    Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.
    
    Link: http://www.lintcode.com/en/problem/majority-number/

    Example: Given [1, 1, 1, 1, 2, 2, 2], return 1.

    Solution: Use a pair of spaces to solve it, meet, add 1, not meet minus 1.
    
    Source: None
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        if (nums.empty()) {
            return 0;            
        }
        int num = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (num != nums[i]) {
                if (count == 0) {
                    num = nums[i];
                    count++;
                } else {
                    count--;
                }
            } else {
                count++;
            }
            
        }
        return num;
    }
};
