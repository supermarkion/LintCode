/*
    Suppose a sorted array is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
	You are given a target value to search. If found in the array return its index, otherwise return -1. You may assume no 
	duplicate exists in the array.

    Link: http://www.lintcode.com/en/problem/search-in-rotated-sorted-array/

    Example: 
    	For [4, 5, 1, 2, 3] and target=1, return 2.
		For [4, 5, 1, 2, 3] and target=0, return -1.

    Solution: In this problem, we should draw a picture to analysis the location of our target values. If it exist duplicate
    numbers, we just add start number to move the location (when mid number equals to start number).

    Source: None
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        if (A.empty()) {
            return -1;
        }
        int start = 0;
        int end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] > A[start]) {
                if (A[start] <= target && target <= A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else {
                if (A[mid] <= target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
            
        }
        if (A[start] == target) {
            return start;
        } else if (A[end] == target) {
            return end;
        }
        return -1;
    }
};