/*
    Given an array of non-negative integers, you are initially positioned at the first index of the array.
	Each element in the array represents your maximum jump length at that position.
	Determine if you are able to reach the last index.

    Link: http://www.lintcode.com/en/problem/jump-game/

    Example: 
    	A = [2,3,1,1,4], return true.
		A = [3,2,1,0,4], return false.

    Solution: In the jump game, we should consider that whether the current index is smaller than farthest available index,
     and if this current index available range plus its location is greater than farthest available index, which means 
     that we can move to this index to get farther locations. Therefore, we move to this index. When we achieve
     the farthest index, if it is greater than end of list, we achieve the end of list.

    Source: None
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        if (A.empty()) {
            return false;
        }
        int farest = A[0];
        for (int i = 0; i < A.size(); i++) {
            if (i <= farest && A[i] + i > farest) {
                farest = i + A[i];
            }
        }
        return farest >= A.size() - 1;
    }
};
