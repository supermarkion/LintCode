/*
    Given an integer array, heapify it into a min-heap array. For a heap array A, A[0] is the root of heap, 
    and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].

    Link: http://www.lintcode.com/en/problem/heapify/

    Example: Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.

    Solution: This task is the process change a list to a heap.

    Source: None
*/

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        for (int i = A.size() / 2; i >= 0; i--) {
            minHeap(A, i);
        }
    }
    
    void minHeap(vector<int> &A, int i) {
        int len = A.size();
        while (i < len) {
            int minIndex = i;
            if (i * 2 + 1 < len && A[i * 2 + 1] < A[minIndex]) {
                minIndex = i * 2 + 1;
            }
            if (i * 2 + 2 < len && A[i * 2 + 2] < A[minIndex]) {
                minIndex = i * 2 + 2;
            }
            if (i == minIndex) {
                break;
            }
            swap(A[i], A[minIndex]);
            i = minIndex;
        }
    }
};