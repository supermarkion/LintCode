/*
    Find the contiguous subarray within an array (containing at least one number) which has the largest product.

    Link: http://www.lintcode.com/en/problem/maximum-product-subarray/

    Example: For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6.

    Solution: The product result is special because its result can change from minimum to maximum only by multiply 
    a negative number. Therefore, we update two list, which save minimum product and maximum product numbers. 
    Once we meet a new positivity number, we compare two list themselves, but if we meet a negative number, 
    we update the list based on different list.

    Source: http://yucoding.blogspot.com.au/2014/10/leetcode-quesion-maximum-product.html
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int res = nums[0];
        int maxp = nums[0];
        int minp = nums[0];
        for (int i = 1;  i < nums.size(); i++){
            int tmpmax = maxp;
            int tmpmin = minp;
            maxp = max(max(tmpmax * nums[i],tmpmin * nums[i]), nums[i]);
            minp = min(min(tmpmax * nums[i],tmpmin * nums[i]), nums[i]);
            res = max(maxp,res);
        }
        return res;
    }
};