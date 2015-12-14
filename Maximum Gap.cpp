/*
    Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
    Return 0 if the array contains less than 2 elements.
    Link: http://www.lintcode.com/en/problem/maximum-gap/
    Example: Given [1, 9, 2, 5], the sorted form of it is [1, 2, 5, 9], the maximum gap is between 5 and 9 = 4.
    Solution: Use the Bucket Sort template to get result.
    Source: http://www.jiuzhang.com/solutions/maximum-gap/
*/


struct Block {
  int max, min;  
};

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        // write your code here
        if (nums.size() < 2) {
            return 0;
        }
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            min = min < nums[i] ? min : nums[i];
            max = max > nums[i] ? max : nums[i];
        }
        if (min == max) {
            return 0;
        }
        int block_size = (max - min) / nums.size() + 1;
        vector<Block> blocks(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            blocks[i].max = blocks[i].min = -1;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int block_id = (nums[i] - min) / block_size;
            if (blocks[block_id].max == -1) {
                blocks[block_id].min = blocks[block_id].max = nums[i];
            } else {
                blocks[block_id].min = blocks[block_id].min < nums[i] ? blocks[block_id].min : nums[i];
                blocks[block_id].max = blocks[block_id].max > nums[i] ? blocks[block_id].max : nums[i];
            }
        }
        
        int maxGap = -1;
        int lastNumber = blocks[0].max;
        for (int i = 0; i < nums.size(); i++) {
            if (blocks[i].min == -1) {
                continue;
            }
            maxGap = maxGap > blocks[i].min - lastNumber ? maxGap :blocks[i].min - lastNumber;
            lastNumber = blocks[i].max;
        }
        return maxGap;
    }
};