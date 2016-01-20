/*
    Given two strings, find the longest common subsequence (LCS). Your code should return the length of LCS.

    Link: http://www.lintcode.com/en/problem/longest-common-subsequence/

    Example: 
    	For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.
		For "ABCD" and "EACB", the LCS is "AC", return 2.

    Solution: Given two strings, find the longest common subsequence (LCS). Your code should return the length of LCS.
	For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1. For "ABCD" and "EACB", the LCS is "AC", return 2. 
	In this problem, we use dynamic programming method to solve.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/longest-common-subsequence.cpp
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if (A.length() < B.length()) {
            return longestCommonSubsequence(B, A);
        }

        // table[i][j] means the longest length of common subsequence
        // of A[0 : i] and B[0 : j].
        vector<vector<int>> table(2, vector<int>(A.length() + 1, 0));

        // if A[i - 1] != B[j - 1]:
        //     table[i][j] = max(table[i - 1][j], table[i][j - 1])
        // if A[i - 1] == B[j - 1]:
        //     table[i][j] = table[i - 1][j - 1] + 1
        for (int i = 1; i < A.length() + 1; ++i) {
            for (int j = 1; j < B.length() + 1; ++j) {
                if (A[i - 1] != B[j - 1]) {
                    table[i % 2][j] = max(table[(i - 1) % 2][j],
                                       table[i % 2][j - 1]);
                } else {
                    table[i % 2][j] = table[(i - 1) % 2][j - 1] + 1;
                }
            }
        }

        return table[A.length() % 2][B.length()];
    }
};
