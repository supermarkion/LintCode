/*
    Given an unsorted integer array, find the first missing positive integer.
    Link: http://www.lintcode.com/en/problem/first-missing-positive/
    Example: 
    	Given [1,2,0] return 3,
		and [3,4,-1,1] return 2.

    Solution: This is not similar to find first missing number because the numbers in this list are not all positive. 
    Moreover, it also has the problem on memory usage. Then, we perform bucket sort, and find the first value which 
    not fulfil the equation that value = index + 1. In this process, we use a definition that the sorted value should
	located at index that value minus one. Then, if we meet a value which are not in its suitable location, we change 
	it to its suitable location (assume the list have enough space).

    Source: None
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        for (int i = 0; i < A.size(); i++) {
            while (A[i] > 0 && A[i] <= A.size() && 
                        A[i] != i + 1 && A[A[i] - 1] != A[i]) {
                swap(A[A[i] - 1], A[i]);
            }
        }
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return A.size() + 1;
    }
};
