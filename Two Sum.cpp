/*
    Given an array of integers, find two numbers such that they add up to a specific target number.
	The function twoSum should return indices of the two numbers such that they add up to the target, 
	where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
	are NOT zero-based.

    Link: http://www.lintcode.com/en/problem/two-sum/

    Example: 
    	numbers = [2, 7, 11, 15], target = 9. return [1, 2]

    Solution: In this problem, it aims to get the minimum closet value to zero. Which means that once we find a new sum
	result which is less than before, we should clean our result list, and insert this new pair. Moreover, in order
	to save time and space complexity, we use a instance named pair which save the end index value and sum
	result from zero index. Then, we sort this pair list, and get the minimum gap between two sum values, and
	get the closet sum of different sub-array.

    Source: https://github.com/kamyu104/LintCode/blob/master/C++/2-sum.cpp
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i) {
            // Check if "target - nums[i]" exists or not
            if (hash.find(target - nums[i]) != hash.end()) {
                return {hash[target - nums[i]] + 1, i + 1};
            }
            hash[nums[i]] = i;
        }

        return {};
    }
};
