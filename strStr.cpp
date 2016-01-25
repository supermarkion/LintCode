/*
    For a given source string and a target string, you should output the first index(from 0) of target string in source string.
    If target does not exist in source, just return -1.

    Link: http://www.lintcode.com/en/problem/strstr/

    Example: 
    	If source = "source" and target = "target", return -1.
		If source = "abcdabcdefg" and target = "bcd", return 1.

    Solution: KMP template in C++
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/strstr.cpp
*/


class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (source != nullptr && target != nullptr) {
            const string src(source), tgt(target);
            if (tgt.empty()) {
                return 0;
            }

            return KMP(src, tgt);
        }
        return -1;
    }


    int KMP(const string& text, const string& pattern) {
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                return i - j;
            }
        }
        return -1;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};
