/*
    Given two sorted integer arrays A and B, merge B into A as one sorted array.
    
    Link: http://www.lintcode.com/en/problem/merge-sorted-array/

    Example: 
    	A = [1, 2, 3, empty, empty], B = [4, 5]
		After merge, A will be filled as [1, 2, 3, 4, 5]

    Solution: Based on this problem, if we want to speed up merge several times, we have to apply divide and merge.
	Then, for the divide method, we divide a the lists into left part and right, and then perform merge them.

    Source: http://www.lintcode.com/en/problem/merge-sorted-array/
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int i = m + n;
        while (m > 0 && n > 0) {
            if (A[m - 1] > B[n - 1]) {
                A[i - 1] = A[m - 1];
                --m;
            } else {
                A[i - 1] = B[n - 1];
                --n;
            }
            --i;
        }

        while (n > 0) {
            A[i - 1] = B[n - 1];
            --n;
            --i;
        }
    }
};