/*
    Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000) and an query list. 
    For each query, give you an integer, return the number of element in the array that are smaller than the given integer.
    Link: http://www.lintcode.com/en/problem/count-of-smaller-number/
    Example: For array [1,2,7,8,5], and queries [1,8,5], return [0,4,2]
    Solution: C++ lower_bound, excited.
    Source: https://github.com/kamyu104/LintCode/blob/master/C++/count-of-smaller-number.cpp
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> result;
        sort(A.begin(), A.end());
        for (int i = 0; i < queries.size(); ++i) {
            const auto it = lower_bound(A.cbegin(), A.cend(), queries[i]);
            result.emplace_back(it - A.cbegin());
        }
        return result;
    }
};