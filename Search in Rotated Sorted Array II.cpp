/*
    Suppose a sorted array is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
	You are given a target value to search. If found in the array return its index, otherwise return -1. You may assume no 
	duplicate exists in the array. What if duplicates are allowed?

    Link: http://www.lintcode.com/en/problem/search-in-rotated-sorted-array-ii/

    Example: 
    	For [4, 5, 1, 2, 3] and target=1, return 2.
		For [4, 5, 1, 2, 3] and target=0, return -1.

    Solution: In this problem, we should draw a picture to analysis the location of our target values. If it exist duplicate
    numbers, we just add start number to move the location (when mid number equals to start number).

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/search-in-rotated-sorted-array-ii.cpp
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target) {
                return true;
            }
            if (A[left] < A[mid]) {
                if (A[left] <= target && target < A[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (A[left] > A[mid]) {
                if (A[mid] < target and target <= A[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                ++left;
            }
        }

        return false;
    }
};