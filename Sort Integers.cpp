/*
    Given an integer array, sort it in ascending order. Use selection sort, bubble sort, insertion sort or any O(n2) algorithm.

    Link: http://www.lintcode.com/en/problem/sort-integers/

    Example: 
    	Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].

    Solution: None

    Source: None
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // Write your code here
        if (A.size() < 1)
        {
            return;
        }
        bool swapp = true;
        while (swapp)
        {
            swapp = false;
            for (int i = 0; i < A.size()-  1; i++)
            {
                if (A[i] > A[i + 1] )
                {
                    swap(A[i], A[i + 1]);
                    swapp = true;
                }
            }
        }
    }
};