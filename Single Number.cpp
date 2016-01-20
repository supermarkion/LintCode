/*
    Given 2*n + 1 numbers, every numbers occurs twice except one, find it.

    Link: http://www.lintcode.com/en/problem/single-number/

    Example: Given [1,2,2,1,3,4,3], return 4

    Solution: Use the definition that XOR operation, and it is easy to get unique number from a list.

    Source: None
*/

class Solution {
public:
    /**
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        // write your code here
        if (A.empty()) {
            return 0;
        }
        int n = A[0];
        for (int i = 1; i < A.size(); i++) {
            n = n ^ A[i];
        }
        return n;
    }
};
