/*
    Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
    (each operation is counted as 1 step.) You have the following 3 operations permitted on a word:
		Insert a character
		Delete a character
		Replace a character
    
    Link: http://www.lintcode.com/en/problem/edit-distance/

    Example: 
    	Given word1 = "mart" and word2 = "karma", return 3.

    Solution: In the problem, it assumes that each string can be change to another change by perform length of string
    operations. Therefore, in the initialize operation of dynamic programming matrix, we increase the values of
    first column and first row. After that, we loop this matrix, when facing a same char between two words, we
    assign this cell with the minimum value of its left-top, left, and top (which means there is no need the add a
    new operation). If they are not same, we also get the minimum vales of its left-top, left and top, but plus 1
    to this cell.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/edit-distance.cpp
*/

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        const size_t m = word1.size();
        const size_t n = word2.size();

        if (m < n) {
            return minDistance(word2, word1);
        }

        vector<vector<int>> steps(2, vector<int>(n + 1, 0));

        for (int j = 0; j < n + 1; ++j) {
            steps[0][j] = j;
        }

        for (int i = 1; i < m + 1; ++i) {
            steps[i % 2][0] = i;
            for (int j = 1; j < n + 1; ++j) {
                steps[i % 2][j] = word1[i - 1] == word2[j - 1] ?
                steps[(i - 1) % 2][j - 1] :
                1 + min(steps[(i - 1) % 2][j - 1],
                        min(steps[(i - 1) % 2][j], steps[i % 2][j - 1]));
            }
        }

        return steps[m % 2][n];
    }
};
