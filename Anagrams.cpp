/*
    Given an array of strings, return all groups of strings that are anagrams.

    Link: http://www.lintcode.com/en/problem/anagrams/

    Example: 
		Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"].
		Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba", "cd", "dc"].

    Solution: We sort each string, to get the same key, then use a table to know whether this is a 
    anagram string or not.

    Source: http://www.lintcode.com/en/problem/anagrams/
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, int> table;

        for (auto str : strs) {
            sort(str.begin(), str.end());
            ++table[str];
        }

        vector<string> anagrams;
        for (const auto& str : strs) {
            string sorted_str(str);		// copy this string
            sort(sorted_str.begin(), sorted_str.end());
            if (table[sorted_str] >= 2) {
                anagrams.emplace_back(str);
            }
        }

        return anagrams;
    }
};
