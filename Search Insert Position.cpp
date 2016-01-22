/*
    Given a sorted array and a target value, return the index if the target is found. If not, return the index where it 
    would be if it were inserted in order. You may assume NO duplicates in the array.
    
    Link: http://www.lintcode.com/en/problem/search-insert-position/

    Example: 
    	[1,3,5,6], 5 → 2
		[1,3,5,6], 2 → 1
		[1,3,5,6], 7 → 4
		[1,3,5,6], 0 → 0

    Solution: The classic binary search process. Note: the mid is start + (end − start) ÷ 2. And the start starts from −1
    and end starts from length of list. And our target index is start plus 1.

    Source: None
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.empty()) {
            return 0;
        }
        int start = -1;
        int end = A.size();
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return start + 1;
    }
};
