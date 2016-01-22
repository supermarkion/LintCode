/*
    Implement function atoi to convert a string to an integer. If no valid conversion could be performed, a zero value is returned.
    If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
    
    Link: http://www.lintcode.com/en/problem/string-to-integer-ii/

    Example: 
    	"10" => 10
        "-1" => -1
        "123123123123123" => 2147483647
        "1.0" => 1

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/string-to-integeratoi.cpp
*/

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        if (str.empty()) {
            return 0;
        }

        int ans = 0;
        int sign = 1;
        int i = 0;

        // Skip ' '.
        while (str[i] == ' ') {
            ++i;
        }

        // Parse sign.
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            sign = -1;
            ++i;
        }

        // Compute integer.
        for (; i < str.length() && isdigit(str[i]); ++i) {
            if (ans > (INT_MAX - (str[i] - '0')) / 10 ||
                ((str[i] - '0') == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) { 
                    return sign > 0 ? INT_MAX : INT_MIN;
            }
            ans *= 10;
            ans += str[i] - '0';
        }

        ans *= sign;
        return ans;
    }
};