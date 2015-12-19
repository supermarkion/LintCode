/*
    Print numbers from 1 to the largest number with N digits by recursion.
    Link: http://www.lintcode.com/en/problem/print-numbers-by-recursion/
    Example:
		Given N = 1, return [1,2,3,4,5,6,7,8,9].
		Given N = 2, return [1,2,3,4,5,6,7,8,9,10,11,12,...,99].
    Solution: Not add result one by one, we construct based on its digits.
    Source: https://github.com/kamyu104/LintCode/blob/master/C++/print-numbers-by-recursion.cpp
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> result;
        numbersByRecursionHelper(0, n, result);
        return result;
    }
    
    void numbersByRecursionHelper(int depth, int n, vector<int>& result) {
        if (depth == n) {
            return;
        }
        if (depth == 0) {
            // size_t: size_t is the type returned by the sizeof operator
            for (size_t d = 1; d <= 9; ++d) {
                result.emplace_back(d);
            }
        } else {
            const size_t count = result.size();
            for (size_t d = 1; d <= 9; ++d) {
                result.emplace_back(d * pow(10, depth)); // pow is: 10^depth
                for (size_t i = 0; i < count; i++) {
                    result.emplace_back(result[i] + d * pow(10, depth));
                }
            }
        }
        numbersByRecursionHelper(depth + 1, n, result);
    }
    
};