/*
    mplement wildcard pattern matching with support for '?' and '*'.
		'?' Matches any single character.
		'*' Matches any sequence of characters (including the empty sequence).
	The matching should cover the entire input string (not partial).

    Link: http://www.lintcode.com/en/problem/wildcard-matching/

    Example:
    	isMatch("aa","a") → false
		isMatch("aa","aa") → true
		isMatch("aaa","aa") → false
		isMatch("aa", "*") → true
		isMatch("aa", "a*") → true
		isMatch("ab", "?*") → true
		isMatch("aab", "c*a*b") → false

    Solution: Similar to RE method.

    Source: http://www.jiuzhang.com/solutions/wildcard-matching/
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL) {
            return false;
        }
        
        int n = strlen(s);
        int m = strlen(p);
        int f[n + 1][m + 1];
        
        // Sets the first num bytes of the block of memory pointed 
        // by ptr to the specified value (interpreted as an unsigned char).
        // void * memset ( void * ptr, int value, size_t num );
        /*

		#include <stdio.h>
		#include <string.h>

		int main ()
		{
		  char str[] = "almost every programmer should know memset!";
		  memset (str,'-',6);
		  puts (str);
		  return 0;
		}

		output:
		------ every programmer should know memset!

        */
        memset(f, false, sizeof(f));
        
        f[0][0] = true;
        for (int i = 1; i <= n; i++)
            f[i][0] = false;
        
        for (int i = 1; i <= m; i++)
            f[0][i] = f[0][i - 1] && p[i - 1] == '*';
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1];
                } else if (p[j - 1] == '?') {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        } // for
        
        return f[n][m];
    }
};