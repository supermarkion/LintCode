/*
    Implement an algorithm to determine if a string has all unique characters.

    Link: http://www.lintcode.com/en/problem/unique-characters/

    Example: 
    	Given "abc", return true.
		Given "aab", return false.

    Solution: Still use a map to save all information.

    Source: None
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        if (str.length() > 256) {
            return false;
        }

        // At most 256 entires, const space.
        unordered_map<char, int> cnt;
        for (const auto& c : str) {
            ++cnt[c];
            if (cnt[c] > 1) {
                return false;
            }
        }

        return true;
    }
};