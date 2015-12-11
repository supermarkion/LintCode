/*
	Given a string s, partition s such that every substring of the partition is a palindrome.
	Return all possible palindrome partitioning of s.
	Link: http://www.lintcode.com/en/problem/palindrome-partitioning/
	Example: Given s = "aab", return:
	[
  	["aa","b"],
  	["a","a","b"]
	]
	Solution: use the process on construct all possible words, but each time make sure it is a
	palindrome or not.
	Source: https://github.com/kamyu104/LintCode/blob/master/C++/palindrome-partitioning.cpp
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partition;
        helper(s, 0, &partition, &result);
        return result;
    }

    // size_t: Alias of one of the fundamental unsigned integer types 
    void helper(const string& s, size_t used,
                vector<string>* partition,
                vector<vector<string>>* result) {
        if (used == s.size()) {
            result->emplace_back(*partition); // have to use ->
            return;
        }

        for (size_t i = used + 1; i <= s.size(); ++i) {
            string prefix = s.substr(used, i - used);
            if (IsPalindrome(prefix)) {
                partition->emplace_back(prefix);
                helper(s, i, partition, result);
                partition->pop_back();
            }
        }
    }

    bool IsPalindrome(const string& s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};