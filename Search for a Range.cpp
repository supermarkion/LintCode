/*
    Given a sorted array of n integers, find the starting and ending position of a given target value.
    If the target is not found in the array, return [-1, -1].
    
    Link: http://www.lintcode.com/en/problem/search-for-a-range/

    Example: 
    	Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].

    Solution: Perform upper and lower bound method to solve this problem.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/search-for-a-range.cpp
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        const int begin = lower_bound(A, target);
        const int end = upper_bound(A, target);

        if (begin < A.size() && A[begin] == target)
            return {begin, end - 1};

        return {-1, -1};
    }

private:
    int lower_bound(vector<int> &A, int target) {
        int left = 0;
        int right = A.size();
        // Find min left s.t. A[left] >= target.
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int upper_bound(vector<int> &A, int target) {
        int left = 0;
        int right = A.size();
        // Find min left s.t. A[left] > target.
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};