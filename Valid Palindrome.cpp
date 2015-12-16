/*
    Given a string, determine if it is a palindrome, considering only alphanumeric characters
    and ignoring cases.
    Link: http://www.lintcode.com/en/problem/valid-palindrome/
    Example: 
        "A man, a plan, a canal: Panama" is a palindrome.
        "race a car" is not a palindrome.
    Solution: The simple solution is based on the filter action on whether this char is a alpha or a number
    based on its char value is between ’a’ and ’z’, and ’0’ and ’9’.
    Source: None
*/

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        if (s.empty()) {
            return true;
        }
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isdigit(s[l]) && !isalpha(s[l])) {
                l++;
                continue;
            }
            if (!isdigit(s[r]) && !isalpha(s[r])) {
                r--;
                continue;
            }
            if (tolower(s[l]) == tolower(s[r])) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
};