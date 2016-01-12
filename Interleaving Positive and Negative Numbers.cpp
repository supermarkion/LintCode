/*
    Given an array with positive and negative integers. Re-range it to interleaving with positive and negative integers.

    Link: http://www.lintcode.com/en/problem/interleaving-positive-and-negative-numbers/

    Example: Given [-1, -2, -3, 4, 5, 6], after re-range, it will be [-1, 5, -2, 4, -3, 6] or any other reasonable answer.

    Solution: Perform two pointer method, remember to record current sorted index.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/interleaving-positive-and-negative-numbers.cpp
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        int n = A.size();
        
        int expectPostive = false;
        int postiveCount = 0;
        
        for (const auto& k : A) {
            postiveCount += k > 0 ? 1 : 0;
        }
        
        if (2 * postiveCount > n) {
            expectPostive = true;
        }
        
        int pos = 0, neg = 0;
        int i = 0;
        
        while (pos < n && neg < n) {
            while (pos < n && A[pos] > 0) {
                ++pos;
            }
            while (neg < n && A[neg] < 0) {
                ++neg;
            }
            
            if (expectPostive && A[i] < 0) {
                swap(A[i], A[neg]);
            }
            
            if (!expectPostive && A[i] > 0) {
                swap(A[i], A[pos]);
            }
            
            if (i == pos) {
                ++pos;
            }
            if (i == neg) {
                ++neg;
            }
            
            expectPostive = !expectPostive;
            ++i;
            
        }
        
    }
};