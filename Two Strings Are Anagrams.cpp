/*
    Write a method anagram(s,t) to decide if two strings are anagrams or not.

    Link: http://www.lintcode.com/en/problem/two-strings-are-anagrams/

    Example: Given s="abcd", t="dcab", return true.

    Solution: Use a map to add chars in 's' string, then minus chars in 't' string, and if meet value less than 0, return false.

    Source: None
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> count;
        
        for (const auto& c : s) {
            ++count[tolower(c)];
        }
        
        for (const auto& c : t) {
            --count[tolower(c)];
            if (count[tolower(c)] < 0) {
                return false;
            }
        }
        
        return true;
    }
};