/*
    Give an integer array，find the longest increasing continuous subsequence in this array.
    An increasing continuous subsequence:
        Can be from right to left or from left to right.
        Indices of the integers in the subsequence should be continuous.

    Link: http://www.lintcode.com/en/problem/longest-increasing-continuous-subsequence/
    
    Example: 
        For [5, 4, 2, 1, 3], the LICS is [5, 4, 2, 1], return 4.
        For [5, 1, 2, 3, 4], the LICS is [1, 2, 3, 4], return 4.
    
    Solution: we update curMax, endMax, but with two directions.
    Source: https://github.com/kamyu104/LintCode/blob/master/C++/longest-increasing-continuous-subsequence.cpp
*/

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int max_inc_len = 0, cur_inc_len = 0;
        int max_dec_len = 0, cur_dec_len = 0;
        
        for (int i = 0; i < A.size(); ++i) {
            if (i == 0 || A[i] == A[i - 1]) {
                max_inc_len = max(max_inc_len, ++cur_inc_len);
                max_dec_len = max(max_dec_len, ++cur_dec_len);
            } else if (A[i] > A[i - 1]) {
                max_inc_len = max(max_inc_len, ++cur_inc_len);
                cur_dec_len = 1;
            } else if (A[i] < A[i - 1]) {
                max_dec_len = max(max_dec_len, ++cur_dec_len);
                cur_inc_len = 1;
            }
        }

        return max(max_inc_len, max_dec_len);
    }
};