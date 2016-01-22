/*
    There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
    
    Link: http://www.lintcode.com/en/problem/median-of-two-sorted-arrays/

    Example: 
    	Given A=[1,2,3,4,5,6] and B=[2,3,4,5], the median is 3.5.
        Given A=[1,2,3] and B=[4,5], the median is 3.

    Solution: We can solve this problem by find the kth number in a sorted array.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/median-of-two-sorted-arrays.cpp
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        if ((A.size() + B.size()) % 2 == 1) {
            return findKthInTwoSortedArrays(A, B, (A.size() + B.size()) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(A, B, (A.size() + B.size()) / 2) +
                    findKthInTwoSortedArrays(A, B, (A.size() + B.size()) / 2 + 1)) / 2.0;
        }
    }

    int findKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                                 int k) {
        const int m = A.size();
        const int n = B.size();

        // Make sure m is the smaller one.
        if (m > n) {
            return findKthInTwoSortedArrays(B, A, k);
        }

        int left = 0;
        int right = m;
        // Find a partition of A and B
        // where min left s.t. A[left] >= B[k - 1 - left]. Thus left is the (k + 1)-th element.
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (0 <= k - 1 - mid && k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : numeric_limits<int>::min();
        int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : numeric_limits<int>::min();

        // kth element would be A[left - 1] or B[k - 1 - left].
        return max(Ai_minus_1, Bj);
    }
};