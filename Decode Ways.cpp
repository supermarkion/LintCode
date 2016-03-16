/*
    A message containing letters from A-Z is being encoded to numbers using the following mapping:
		'A' -> 1
		'B' -> 2
		...
		'Z' -> 26
	Given an encoded message containing digits, determine the total number of ways to decode it.
    
    Link: http://www.lintcode.com/en/problem/decode-ways/#

    Example: 
    	Given encoded message 12, it could be decoded as AB (1 2) or L (12). The number of ways decoding 12 is 2.

    Solution: None

    Source: None
*/

class Solution {
public:
    int numDecodingsHelper(string s, int p, vector<int>& flag) {
        if (p == s.length() || s[p] == '0') {
            flag [p] = s[p] == '0' ? 0 : 1;
            return flag[p];
        }

        flag[p] = flag[p + 1] == -1 ? numDecodingsHelper(s, p + 1, flag) : flag[p + 1];
        if (p == s.length() - 1) {
            return flag[p];
        }

        if (s[p] == '1' || (s[p] == '2' && s[p + 1] <= '6')) {
            flag[p] += flag[p + 2] == -1 ? numDecodingsHelper(s, p + 2, flag) : flag[p + 2];
        }
        return flag[p];
    }

    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        if (s.length() == 0) {
            return 0;
        }
        vector<int> flag(s.length() + 1, -1);
        int res = numDecodingsHelper(s, 0, flag);
        return res;
    }
};