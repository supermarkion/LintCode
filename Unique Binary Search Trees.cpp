/*
    Given n, how many structurally unique BSTs (binary search trees) that store values 1...n?

    Link: http://www.lintcode.com/en/problem/unique-binary-search-trees/

    Example:
    	Given n = 3, there are a total of 5 unique BST's.
		1           3    3       2      1
		 \         /    /       / \      \
		  3      2     1       1   3      2
		 /      /       \                  \
		2     1          2                  3

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/unique-binary-search-trees.cpp
*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if (n == 0) {
            return 1;
        }
        return combination(2 * n, n) - combination(2 * n, n - 1);
    }

    int combination(const int  n, const int k) {
        long long count = 1;
        // C(n, k) = (n) / 1 * (n - 1) / 2 ... * (n - k + 1) / k
        for (int i = 1; i <= k; ++i) {
            count = count * (n - i + 1) / i;
        }

        return count;
    }
};