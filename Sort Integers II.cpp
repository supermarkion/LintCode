/*
    Given an integer array, sort it in ascending order. Use quick sort, merge sort, heap sort or any O(nlogn) algorithm.

    Link: http://www.lintcode.com/en/problem/sort-integers-ii/

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
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        if (A.size() < 1)
        {
            return;
        }
        quickSort(A, 0, A.size() - 1);
    }
    
private:
    void quickSort(vector<int>& arr, int left, int right) {
        int i = left, j = right;
        int tmp;
        int pivot = arr[(left + right) / 2];
     
        /* partition */
        while (i <= j) 
        {
            while (arr[i] < pivot)
            {
              	i++;
            }
            while (arr[j] > pivot)
            {
              	j--;
            }
            if (i <= j) 
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        };
     
        /* recursion */
        if (left < j)
        {
        	quickSort(arr, left, j);
        }
                
        if (i < right)
        {
        	quickSort(arr, i, right);
        }  
    }
};