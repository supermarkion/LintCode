/*
    Compare two strings A and B, determine whether A contains all of the characters in B. The characters in string A 
    and B are all Upper Case letters.
    
    Link: http://www.lintcode.com/en/problem/compare-strings/

    Example: 
    	For A = "ABCD", B = "ACD", return true.
		For A = "ABCD", B = "AABC", return false.

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/compare-strings.cpp
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        unordered_map<char, int> h;
        for (const auto& c: A) {
            ++h[c];
        }

        for (const auto& c: B) {
            if (--h[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
