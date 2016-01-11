/*
    Implement regular expression matching with support for '.' and '*'.
        '.' Matches any single character.
        '*' Matches zero or more of the preceding element.
    The matching should cover the entire input string (not partial).
        The function prototype should be:
        bool isMatch(const char *s, const char *p)

    Link: http://www.lintcode.com/en/problem/regular-expression-matching/

    Example: 
    	isMatch("aa","a") → false
        isMatch("aa","aa") → true
        isMatch("aaa","aa") → false
        isMatch("aa", "a*") → true
        isMatch("aa", ".*") → true
        isMatch("ab", ".*") → true
        isMatch("aab", "c*a*b") → true

    Solution: Use dynamic programmng to save process infomration.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/regular-expression-matching.cpp
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        const size_t s_len = strlen(s);
        const size_t p_len = strlen(p);

        // match[i][j] denotes as:
        // s[0, i - 1] matches p[0, j - 1] or not.
        vector<vector<bool>> match(s_len + 1, vector<bool>(p_len + 1));

        match[0][0] = true;
        for (int i = 2; i <= p_len; ++i) {
            if (p[i - 1] == '*') {
                match[0 % 2][i] = match[0 % 2][i - 2];
            }
        }

        for (int i = 1; i <= s_len; ++i) {
            match[i % 2][0] = false;
            for (int j = 1; j <= p_len; ++j) {
                if (p[j - 1] != '*') {
                    match[i % 2][j] = match[(i - 1) % 2][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                } else {
                    match[i % 2][j] = j >= 2 && (match[i % 2][j - 2] || (match[(i - 1) % 2][j] && (p[j - 2] == s[i - 1] || p[j - 2]=='.')));
                }
            }
        }
        return match[s_len % 2][p_len];
    }
};