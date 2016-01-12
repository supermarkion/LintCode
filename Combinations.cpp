/*
    Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

    Link: http://www.lintcode.com/en/problem/combinations/

    Example: For example,
        If n = 4 and k = 2, a solution is:
        [[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]

    Solution: Construct all possible solution, remember pop last reminder.

    Source: https://github.com/kamyu104/LintCode/blob/master/C++/combinations.cpp
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int>> result;
        vector<int> ans;
        CombinationsHelper(n, k, 1, &ans, &result);
        return result;
    }
    
    void CombinationsHelper(int n, int k, int start, vector<int>* ans,
                            vector<vector<int>>* result) {
        if (ans->size() == k) {
            result->emplace_back(*ans);
            return;
        }
        
        for (int i = start; i <= n && k - ans->size() <= n - i + 1; ++i) {
            ans->emplace_back(i);
            CombinationsHelper(n, k, i + 1, ans, result);
            ans->pop_back();
        }
    }
};