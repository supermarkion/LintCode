/*
    Given an input string, reverse the string word by word.
    
    Link: http://www.lintcode.com/en/problem/reverse-words-in-a-string/

    Example: For example, Given s = "the sky is blue", return "blue is sky the".

    Solution: Reverse all string, and reverse all words.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/reverse-words-in-a-string.cpp
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        // Reverse the whole string first.
        reverse(s.begin(), s.end());

        size_t start = 0, end;
        while ((end = s.find(" ", start)) != string::npos) {
            // npos is a static member constant value with the greatest possible value for an element of type size_t.
            // Reverse each word in the string.
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        // Reverse the last word.
        reverse(s.begin() + start, s.end());

        // Remove beginning blank.
        if ((start = s.find_first_not_of(" ")) != string::npos) {
            return s.substr(start);
        }

        return s;
    }
};