/*
    Merge two given sorted integer array A and B into a new sorted integer array.

    Link: http://www.lintcode.com/en/problem/merge-sorted-array-ii/

    Example: 
    	A=[1,2,3,4]
		B=[2,4,5,6]
		return [1,2,2,3,4,4,5,6]

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/merge-sorted-array-ii.cpp
*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> C(A.size() + B.size());

        int i = 0;
        int j = 0;

        // Stop comparing while one of array ends.
        // Smaller one has high possibility to end first.
        while (i < A.size() && j < B.size()) {
            if (A[i] >= B[j]) {
                C[i + j] = B[j];
                ++j;
            } else {
                C[i + j] = A[i];
                ++i;
            }
        }

        // Copy the remaining elements to the new array.
        if (i < A.size()) {
            copy(A.cbegin() + i, A.cend(), C.begin() + i + j);
        } else if (j < B.size()) {
            copy(B.cbegin() + j, B.cend(), C.begin() + i + j);
        }

        return C;
    }
};