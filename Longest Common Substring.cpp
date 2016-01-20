/*
    Given two strings, find the longest common substring. Return the length of it.

    Link: http://www.lintcode.com/en/problem/longest-common-substring/

    Example: Given A = "ABCD", B = "CBCE", return 2.

    Solution: Given two strings, find the longest common substring. Return the length of it. The only different of LCS, is
	that in the opt matrix, it construct from 1 to end, and when two strings have the same char, then assign its
	location to left-top plus 1. FOr the LCS, it assign right-down plus 1 when facing a same char. Moreover, int
	the LCSs, it assigns other indexes to 0. But for the LCS, it assigns the max values of right and down values.
	The similar things is that they both return the max values in the matrix as their target numbers.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/longest-common-substring.cpp
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        if (A.length() < B.length()) {
            return longestCommonSubstring(B, A);
        }

        // table[i][j] means the longest length of common substring
        // of A which ends with A[i - 1] and B which ends with B[j - 1].
        vector<vector<int>> table(2, vector<int>(A.length() + 1, 0));
        int longest = 0;

        // if A[i - 1] != B[j - 1]:
        //     table[i][j] = 0
        // if A[i - 1] == B[j - 1]:
        //     table[i][j] = table[i - 1][j - 1] + 1
        for (int i = 1; i < A.length() + 1; ++i) {
            for (int j = 1; j < B.length() + 1; ++j) {
                if (A[i - 1] != B[j - 1]) {
                    table[i % 2][j] = 0;
                } else {
                    table[i % 2][j] = table[(i - 1) % 2][j - 1] + 1;
                    longest = max(longest, table[i % 2][j]);
                }
            }
        }

        return longest;
    }
};
