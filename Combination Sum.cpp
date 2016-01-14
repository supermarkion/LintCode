/*
    Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where 
    the candidate numbers sums to T. The same repeated number may be chosen from C unlimited number of times.

    Link: http://www.lintcode.com/en/problem/combination-sum/

    Example: given candidate set 2,3,6,7 and target 7, A solution set is: 
		[7] 
		[2, 2, 3] 

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/combination-sum.cpp
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSumHelper(candidates, target, 0, v, ans);
        return ans;
    }

private:
    void combinationSumHelper(vector<int>& num, int gap, int begin,
                              vector<int>& v,vector<vector<int>> &ans) {
        if (gap == 0) {
            ans.emplace_back(v);
            return;
        }

        for (size_t i = begin; i < num.size() && num[i] <= gap; ++i) {
            v.emplace_back(num[i]);
            combinationSumHelper(num, gap - num[i], i, v, ans);
            v.pop_back();
        }
    }
};