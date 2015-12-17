/*
    Find the Nth number in Fibonacci sequence.
    Link: http://www.lintcode.com/en/problem/fibonacci/
    Example: 
    	Given 1, return 0
		Given 2, return 1
		Given 10, return 34
    Solution: https://github.com/kamyu104/LintCode/blob/master/C++/fibonacci.cpp
    Source: None
*/

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        if (n <= 1) {
            return n - 1;
        }

        int n_i = 1, n_i_1 = 1, n_i_2 = 0;
        for (int i = 2; i < n; ++i) {
            n_i = n_i_1 + n_i_2;
            n_i_2 = n_i_1;
            n_i_1 = n_i;
        }

        return n_i;
    }
};
