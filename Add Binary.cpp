/*
    Given two binary strings, return their sum (also a binary string).
    Link: http://www.lintcode.com/en/problem/add-binary/
    Example:
    	a = 11
		b = 1
		Return 100
    Solution: Use a string to update the sum result. By the way, once we change the 2 to any bits number,
    we can transform this function to string add to bits.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/add-binary.cpp
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        string result;
        int result_length = max(a.length(), b.length());
        
        int carry = 0;
        for (int i = 0; i < result_length; i++) {
            int a_bit_i = i < a.length() ? a[a.length() - 1 - i] - '0' : 0;
            int b_bit_i = i < b.length() ? b[b.length() - 1 - i] - '0' : 0;
            int sum = carry + a_bit_i + b_bit_i;
            carry = sum / 2;
            sum %= 2;
            result.push_back('0' + sum);
        }
        if (carry) {
            result.push_back('0' + carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};