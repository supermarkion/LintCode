/*
    Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?

    Link: http://www.lintcode.com/en/problem/backpack/

    Example: If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], so that 
    the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we 
    can fulfill the backpack.

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/backpack.cpp
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        // table[i][j] denotes whether using the first elements
        // could fulfill size j.
        vector<vector<bool>> table(2, vector<bool>(m + 1, false));
        int max_size = 0;
        table[0][0] = true;

        for (int i = 1; i <= A.size(); ++i) {
            table[i % 2][0] = true;
            for (int j = 1; j <= m; ++j) {
                // If first i - 1 elements could fulfill the backpack, then
                // first i elements would also do.
                table[i % 2][j] = table[(i - 1) % 2][j];

                // Using the ith element to fulfill the backpack.
                if (j >= A[i - 1]) {
                    table[i % 2][j] = table[i % 2][j]
                    || table[(i - 1) % 2][j - A[i - 1]];
                }

                // If it fulfulls size j, update max size.
                if (table[i % 2][j]) {
                    max_size = max(max_size, j);
                }
            }
        }

        return max_size;
    }
};