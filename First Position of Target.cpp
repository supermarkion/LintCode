/*
    For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.
	If the target number does not exist in the array, return -1.

    Link: http://www.lintcode.com/en/problem/first-position-of-target/

    Example: If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

    Solution: Binary search
    
    Source: http://www.jiuzhang.com/solutions/first-position-of-target/
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if (array.empty()) {
            return -1;
        }
        int start = 0;
        int end = array.size() - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (array[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (array[start] == target) {
            return start;
        }
        
        if (array[end] == target) {
            return end;
        }
        return -1;
    }
};