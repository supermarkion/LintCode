/*
    Given k strings, find the longest common prefix (LCP).

    Link: http://www.lintcode.com/en/problem/longest-common-prefix/

    Example: 
    	For strings "ABCD", "ABEF" and "ACEF", the LCP is "A"
		For strings "ABCDEFG", "ABCEFG" and "ABCEFA", the LCP is "ABC"

    Solution: In this problem, it is easy to solve by compare the prefix based on chars in first string. When facing the
	different, we return the current result.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/longest-common-prefix.cpp
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if (strs.size() == 0) {
            return "";
        }

        auto prefix_len = strs[0].length();
        for (int i = 0; i < prefix_len; ++i) {
            for (const auto& str : strs) {
                if (str[i] != strs[0][i]) {
                    prefix_len = i;
                    break;
                }
            }
        }

        return strs[0].substr(0, prefix_len);
    }
};