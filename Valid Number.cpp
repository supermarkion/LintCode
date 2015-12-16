/*
    Validate if a given string is numeric.
    Link: http://www.lintcode.com/en/problem/valid-number/
    Example: 
        "0" => true
        " 0.1 " => true
        "abc" => false
        "1 a" => false
        "2e10" => true
    Solution: When we meet a string, when should skip the empty spaces between and after string. Then, we skip the
    signal of string (if it has). Then, once we meet a character is digit, we set number flag is true. Once we meet
    a dot, we set dot flag is true. Once we meet a e, if current is not a number or not a exp, it return false, or
    we set exp flag is true, and number flag is false. If we meet a plus or minus operation, if the character before
    it not the e, it also false.
    Source: None
*/

class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        int len = s.size();
        int i = 0, e = len - 1;
        
        // skip empty spaces between and after string
        while (i <= e && isspace(s[i])) {
            i++;
        }
        while (e >= i && isspace(s[e])) {
            e--;
        }
        // skip symbol
        if (i <= e && (s[i] == '+' || s[i] == '-')) {
            i++;
        }
        bool num = false;
        bool dot = false;
        bool exps = false;
        while (i <= e) {
            if (isdigit(s[i])) {
                num = true;
            } else if (s[i] == '.') {
                dot = true;
            } else if (s[i] == 'e') {
                if (exps || num == false) {
                    return false;
                }
                exps = true;
                num = false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (s[i - 1] != 'e') {
                    return false;
                }
            } else {
                return false;
            }
            i++;
        }
        return num;
    }
};