/*
    Given a roman numeral, convert it to an integer.
    The answer is guaranteed to be within the range from 1 to 3999.
    Link: http://www.lintcode.com/en/problem/roman-to-integer/
    Example: 
        IV -> 4
        XII -> 12
        XXI -> 21
        XCIX -> 99
    Solution: When we want to convert Roman to integer, we could use the definition that when
    right number is less than current one, we plus the current number, else, we minus current number.
    Source: None
*/

class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // Write your code here
        if (s.empty()) {
            return 0;
        }
        unordered_map<char, int> map;
        map.emplace('I', 1);
        map.emplace('V', 5);
        map.emplace('X', 10);
        map.emplace('L', 50);
        map.emplace('C', 100);
        map.emplace('D', 500);
        map.emplace('M', 1000);
        
        int result = map[s.back()];
        for (int i = s.size() - 2; i > -1; i--) {
            if (map[s[i + 1]] <= map[s[i]]) {
                result += map[s[i]];
            } else {
                result -= map[s[i]];
            }
        }
        return result;
    }
};