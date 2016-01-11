/*
    Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C 
    where the candidate numbers sums to T.
    Each number in C may only be used once in the combination.

    Link: http://www.lintcode.com/en/problem/combination-sum-ii/
    Example: For example, given candidate set 10,1,6,7,2,1,5 and target 8,
        A solution set is: 
            [1,7]
            [1,2,5]
            [2,6]
            [1,1,6]

    Solution: find reminer and current values left in C can construct a solution, if yes, add, or pop out.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/combination-sum-ii.cpp
*/

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum2Helper(num, target, 0, v, ans);
        return ans;
    }

private:
    void combinationSum2Helper(vector<int>& num, int gap, int begin,
                               vector<int>& v,vector<vector<int>> &ans) {
        if (gap == 0) {
            ans.emplace_back(v);
            return;
        }

        for (size_t i = begin; i < num.size() && num[i] <= gap; ++i) {
            if ( i == begin || num[i] != num[i - 1]) {  // Skip duplicates.
                // Each same element could be chosen only once
                // with the same previous nums.
                v.emplace_back(num[i]);
                combinationSum2Helper(num, gap - num[i], i + 1, v, ans);
                v.pop_back(); // if not construct a solution, pop previous content
            }
        }
    }
};