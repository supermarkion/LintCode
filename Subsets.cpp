/*
    Given a set of distinct integers, return all possible subsets.

    Link: http://www.lintcode.com/en/problem/subsets/

    Example: If S = [1,2,3], a solution is:
		[
		  [3],
		  [1],
		  [2],
		  [1,2,3],
		  [1,3],
		  [2,3],
		  [1,2],
		  []
		]

    Solution: We perform DFS method to solve it, and construct a template.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/subsets.cpp
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	const int size = nums.size();
        const int set_size = 1 << size;
        vector<vector<int>> ans;
        vector<int> v;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < set_size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) {
                    v.emplace_back(nums[j]);
                }
            }
            ans.emplace_back(v);
            v.clear();
        }

        return ans;
    }
};