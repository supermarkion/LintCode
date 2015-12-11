/*
    Given a digit string, return all possible letter combinations that the number could represent.
    A mapping of digit to letters (just like on the telephone buttons) is given below.
    Link: http://www.lintcode.com/en/problem/letter-combinations-of-a-phone-number/
    Example: Given "23"
    Return ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
    Solution: use a vector, and transform digit to index, after that, we use these two sub-vector
    to construct all results.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/letter-combinations-of-a-phone-number.cpp
*/

class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        if (digits.empty()) {
            return {};
        }
        
        vector<string> result = {""};
        vector<string> lookup = {"", "", "abc", "def",
                                 "ghi", "jkl", "mno",
                                 "pqrs", "tuv", "wxyz"};
                                 
        for (int i = digits.size() - 1; i >= 0; --i) {
            const string& choices = lookup[digits[i] - '0'];
            const int n = result.size(), m = choices.length();
            for (int j = n; j < m * n; ++j) {
                result.emplace_back(result[j % n]);
            }
            for (int j = 0; j < m * n; ++j) {
                result[j].insert(result[j].end(), choices[j / n]);
            }
        }
        for (auto& s : result) {
            reverse(s.begin(), s.end());
        }
        
        return result;
    }
};