/*
    Given two array of integers(the first array is array A, the second array is array B), now we are going to find 
    a element in array A which is A[i], and another element in array B which is B[j], so that the difference between 
    A[i] and B[j] (|A[i] - B[j]|) is as small as possible, return their smallest difference.
    Link: http://www.lintcode.com/en/problem/the-smallest-difference/
    Example: For example, given array A = [3,6,7,4], B = [2,8,9,3], return 0
    Solution: Sort firstly, then compare one by one.
    Source: None
*/

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) 
    {
        // write your code here
        if (A.empty() || B.empty()) 
        {
            return 0;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int aIndex = 0;
        int bIndex = 0;
        int diff = INT_MAX;
        while (aIndex < A.size() && bIndex < B.size()) 
        {
            if (A[aIndex] <= B[bIndex]) 
            {
                diff = min(diff, B[bIndex] - A[aIndex++]);
            } 
            else 
            {
                diff = min(diff, A[aIndex] - B[bIndex++]);
            }
            if (diff == 0) 
            {
                return 0;
            }
        }
        
        // compare the rest all numbers
        if (bIndex != B.size() - 1) 
        {
            while (bIndex < B.size()) {
                diff = min(diff, abs(A[aIndex - 1] - B[bIndex++]));
            }
        } 
        else 
        {
            while (aIndex < A.size()) 
            {
                diff = min(diff, abs(A[aIndex++] - B[bIndex - 1]));
            }
        }
        
        return diff;
    }
};
