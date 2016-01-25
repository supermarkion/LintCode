/*
    Given a list of numbers, return all possible permutations.

    Link: http://www.lintcode.com/en/problem/permutations/

    Example: For nums = [1,2,3], the permutations are:
		[
		  [1,2,3],
		  [1,3,2],
		  [2,1,3],
		  [2,3,1],
		  [3,1,2],
		  [3,2,1]
		]

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/permutations.cpp
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        do {
            result.emplace_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        // next_permutation: Rearranges the elements in the range [first,last) 
        // into the next lexicographically greater permutation.
        return result;
    }
};