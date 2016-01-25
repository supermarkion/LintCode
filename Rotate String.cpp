/*
    Given a string and an offset, rotate string by offset. (rotate from left to right)
    
    Link: http://www.lintcode.com/en/problem/rotate-string/

    Example: Given "abcdefg".
        offset=0 => "abcdefg"
        offset=1 => "gabcdef"
        offset=2 => "fgabcde"
        offset=3 => "efgabcd"

    Solution: None
    
    Source: None
*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        if (!str.empty()) {
            offset %= str.length();
            reverse(str.begin(), str.begin() + str.length() - offset);
            reverse(str.begin() + str.length() - offset, str.end());
            reverse(str.begin(), str.end());
        }
    }
};
