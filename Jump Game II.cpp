/*
    Given an array of non-negative integers, you are initially positioned at the first index of the array.
    Each element in the array represents your maximum jump length at that position.
    Your goal is to reach the last index in the minimum number of jumps.

    Link: http://www.lintcode.com/en/problem/jump-game-ii/

    Example: 
    	Given array A = [2,3,1,1,4]
        The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

    Solution: We use a range to represent to available area.
    
    Source: None
*/

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        if (A.empty()) {
            return 0;
        }
        int start = 0, end = 0, jumps = 0;
        while (end < A.size() - 1) {
            int farthest = end;
            for (int i = start; i <= end; i++) { // try each index in range
                if (i + A[i] >= farthest) {
                    farthest = i + A[i];
                }
            }
            if (end < farthest) {
                jumps++;
                start = end + 1; // represt to a range
                end = farthest;
                // after this, we update the range
            } else {
                return -1;
            }
        }
        return jumps;
    }
};