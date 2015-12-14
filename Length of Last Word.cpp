/*
    Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
	If the last word does not exist, return 0.
    Link: http://www.lintcode.com/en/problem/length-of-last-word/
    Example: Given s = "Hello World", return 5.
    Solution: Conut from start or end, the time complexity are similar.
    Source: None
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        if (s.empty()) {
            return 0;
        }
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                result = 0;
            } else {
                result++;
            }
        }
        return result;
    }
};