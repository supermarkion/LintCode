/*
    Given a string, find the length of the longest substring without repeating characters.
    Link: http://www.lintcode.com/en/problem/longest-substring-without-repeating-characters/
    Example: 
    	For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
		For "bbbbb" the longest substring is "b", with the length of 1.
    Solution: Given a string, find the length of the longest substring without repeating characters. In this task, 
    when we meet a repeat character, we should use another index to delete all characters before this repeat character,
	not delete all characters.
    Source: None
*/

 class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        if (s.empty()) {
            return 0;
        }
        unordered_set<char> set;
        int leftBound = 0, maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (set.count(s[i])) {
                while (leftBound < i && s[leftBound] != s[i]) {
                    set.erase(s[leftBound]);
                    leftBound++;
                }
                leftBound++;
            } else {
                set.emplace(s[i]);
                maxLength = max(maxLength, i - leftBound + 1);
            }
        }
        return maxLength;
    }
};