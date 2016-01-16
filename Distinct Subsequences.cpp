/*
    Given a string S and a string T, count the number of distinct subsequences of T in S.
	A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the 
	characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" 
	while "AEC" is not).
    
    Link: http://www.lintcode.com/en/problem/distinct-subsequences/

    Example: 
    	Given S = "rabbbit", T = "rabbit", return 3.

    Solution: We use a range to represent to available area.
    
    Source: None
*/

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        if (S.empty()) {
            return 0;
        }
        if (S.length() < T.length()) {
            return 0;
        }
        if (T.empty()) {
            return 1;
        }
        vector<vector<int>> dp(S.length() + 1, vector<int>(T.length() + 1, 0));
        
        for (int i = 0; i < S.length(); i++) {
            dp[i][0] = 1;
            for (int j = 0; j < T.length(); j++) {
                if (S[i] == T[j]) {
                    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i][j];
                } else {
                    dp[i + 1][j + 1] = dp[i][j + 1]; 
                }
            }
        }
        return dp[S.length()][T.length()];
    }
};
