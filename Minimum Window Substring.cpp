/*
    Given a string source and a string target, find the minimum window in source which will contain all the characters in target.
    
    Link: http://www.lintcode.com/en/problem/minimum-window-substring/

    Example: For source = "ADOBECODEBANC", target = "ABC", the minimum window is "BANC"

    Solution: http://bangbingsyb.blogspot.com.au/2014/11/leetcode-minimum-window-substring.html
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/minimum-window-substring.cpp
*/

class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        if (source.empty() || source.length() < target.length()) {
            return "";
        }

        const int ASCII_MAX = 256;

        vector<int> expCnt(ASCII_MAX, 0);
        vector<int> curCnt(ASCII_MAX, 0);

        int cnt = 0;
        int start = 0;
        int min_width = INT_MAX;
        int min_start = 0;

        for (const auto& c : target) {
            ++expCnt[c];
        }

        for (int i = 0; i < source.length(); ++i) {
            if (expCnt[source[i]] > 0) {
                ++curCnt[source[i]];
                if (curCnt[source[i]] <= expCnt[source[i]]) {  // Counting expected elements.
                    ++cnt;
                }
            }
            if (cnt == target.size()) {  // If window meets the requirement.
                while (expCnt[source[start]] == 0 ||  // Adjust left bound of window.
                       curCnt[source[start]] > expCnt[source[start]]) {
                    --curCnt[source[start]];
                    ++start;
                }

                if (min_width > i - start + 1) {  // Update minimum window.
                    min_width = i - start + 1;
                    min_start = start;
                }
            }
        }

        if (min_width == INT_MAX) {
            return "";
        }

        return source.substr(min_start, min_width);
    }
};
