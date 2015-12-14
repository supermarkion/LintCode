/*
    Given an integer array, find a continuous subarray where the sum of numbers is the biggest.
    Your code should return the index of the first number and the index of the last number.
    (If their are duplicate answer, return anyone)
    Link: http://www.lintcode.com/en/problem/continuous-subarray-sum/
    Example: Give [-3, 1, 3, -3, 4], return [1,4].
    Solution: Use quick and slow pointer approach to solve it and get optimization value (curMax and endMax).
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/continuous-subarray-sum.cpp
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        if (A.empty()) {
            return {-1, -1};
        }
        vector<int> result = {0, 0};
        int curMax = A[0];
        int endMax = A[0];
        for (int i = 0, j = 1; j < A.size(); j++) {
            if (curMax < 0) { // when we assign cur max small than 0
                i = j;        // there is no need to use current range between i and j
                curMax = 0;
            }
            curMax += A[j];
            if (curMax > endMax) {
                endMax = curMax;
                result[0] = i, result[1] = j;
            }
        }
        return result;
    }
};