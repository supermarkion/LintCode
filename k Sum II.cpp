/*
    Given n unique integers, number k (1<=k<=n) and target. Find all possible k integers where their sum is target.

    Link: http://www.lintcode.com/en/problem/k-sum-ii/

    Example: Given [1,2,3,4], k = 2, target = 5. Return:
		[
		  [1,4],
		  [2,3]
		]

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/k-sum-ii.cpp
*/

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int>> ans;
        vector<int> curr;
        helper(A, k, 0, target, curr, ans);
        return ans;
    }

    void helper(vector<int> A, int k, int start, int target, vector<int>& curr, vector<vector<int>> & ans) {
        if (k < 0 || target < 0) {
            return;
        }

        if (k == 0 && target == 0) {
            ans.emplace_back(curr);
            return;
        }

        for (int i = start; i <= A.size() - k; i++) {
            curr.emplace_back(A[i]);
            helper(A, k - 1, i + 1, target - A[i], curr, ans);
            curr.pop_back();
        }
    }
};