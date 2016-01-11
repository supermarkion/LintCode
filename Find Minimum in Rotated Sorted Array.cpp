/*
    Suppose a sorted array is rotated at some pivot unknown to you beforehand.
    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). Find the minimum element.

    Link: http://www.lintcode.com/en/problem/find-minimum-in-rotated-sorted-array/

    Example:
      Given [4, 5, 6, 7, 0, 1, 2] return 0

    Solution: perform binary search to find minimum value.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/find-minimum-in-rotated-sorted-array.cpp
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int left = 0;
        int right = num.size() - 1;

        // Find min left s.t. num[left] < num[left'].
        while (left < right && num[left] >= num[right]) {
            int mid = left + (right - left) / 2;
            if (num[mid] < num[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return num[left];
    }
};