/*
    Given an array and a value, remove all occurrences of that value in place and return the new length.
	The order of elements can be changed, and the elements after the new length don't matter.

    Link: http://www.lintcode.com/en/problem/remove-element/

    Example: Given an array [0,4,4,0,0,2,4,4], value = 4
	return 4 and front four elements of the array is [0,0,0,2]
    
    Solution: Same to partitication process in search to solve steps.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/remove-element.cpp
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int left = 0;
        int right = A.size();
        while (left < right) {
            if (A[left] != elem) {
                ++left;
            } else {
                swap(A[left], A[--right]);
            }
        }
        return left;
    }
};