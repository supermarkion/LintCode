/*
    Suppose a sorted array is rotated at some pivot unknown to you beforehand.
	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
	Find the minimum element. The array may contain duplicates.

    Link: http://www.lintcode.com/en/problem/find-minimum-in-rotated-sorted-array-ii/

    Example:
      Given [4,4,5,6,7,0,1,2] return 0

    Solution: perform binary search to find minimum value, and if two pointers are equal, move left pointer.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/find-minimum-in-rotated-sorted-array-ii.cpp
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
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
            } else if (num[mid] > num[left]) {
                left = mid + 1;
            } else {
                ++left;
            }
        }

        return num[left];
    }
};