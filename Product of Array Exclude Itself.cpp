/*
    Given an integers array A. Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B WITHOUT divide operation.
    
    Link: http://www.lintcode.com/en/problem/product-of-array-exclude-itself/

    Example: For A = [1, 2, 3], return [6, 3, 2].

    Solution: In this problem, we use the multiply results from left to right, and right to left, then sum them to get our
    result result.
    
    Source: None
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> res;
        if (nums.empty()) {
            return res;
        }
        if (nums.size() == 1) {
            res.emplace_back(1);
            return res;
        }
        long long lProduct[nums.size()];
        long long rProduct[nums.size()];
        lProduct[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            lProduct[i] = lProduct[i - 1] * nums[i - 1];
        }
        rProduct[nums.size() - 1] = 1;
        for (int j = nums.size() - 2; j >= 0; j--) {
            rProduct[j] = rProduct[j + 1] * nums[j + 1];
        }
        for (int k = 0; k < nums.size(); k++) {
            res.emplace_back(lProduct[k] * rProduct[k]);
        }
        return res;
    }
};