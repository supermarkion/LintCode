/*
    Given an integer, convert it to a roman numeral. The number is guaranteed to be within the range from 1 to 3999.
    Link: http://www.lintcode.com/en/problem/integer-to-roman/
    Example: 
        4 -> IV
        12 -> XII
        21 -> XXI
        99 -> XCIX
    Solution: When we want to go back, it can perform as its definition. In order to simply the process, we also define
    the number 90 direct to CD.
    Source: None
*/

class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // Write your code here
        stringstream ss;
        string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for (int i = 0; n!= 0; i++) {
            while (n >= values[i]) {
                n -= values[i];
                ss << symbol[i];
            }
        }
        return ss.str();
    }
};
