/*
    There is an integer array which has the following features:
        The numbers in adjacent positions are different.
        A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
    We define a position P is a peek if:
        A[P] > A[P-1] && A[P] > A[P+1]
    Find a peak element in this array. Return the index of the peak.

    Link: http://www.lintcode.com/en/problem/find-peak-element/

    Example: Given [1, 2, 1, 3, 4, 5, 7, 6]
        Return index 1 (which is number 2) or 6 (which is number 7)

    Solution: Write a method to test it is fulfil the peak condition. If is not, we move to a greater postion to find the peak.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/find-peak-element.cpp
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int left = 1;
        int right = A.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid - 1] <= A[mid] && A[mid] >= A[mid + 1]) {
                return mid;
            } else if (A[mid - 1] > A[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
