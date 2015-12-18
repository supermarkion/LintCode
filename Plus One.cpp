/*
    Given a non-negative number represented as an array of digits, plus one to the number.
	The digits are stored such that the most significant digit is at the head of the list.
    Link: http://www.lintcode.com/en/problem/plus-one/
    Example:
    	Given [1,2,3] which represents 123, return [1,2,4].
		Given [9,9,9] which represents 999, return [1,0,0,0].
    Solution: None
    Source: None
*/

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        if (digits.empty()) {
            return digits;
        }
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 == 10) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                break;
            }
        }
        if (digits[0] == 0) {
            digits.emplace(digits.begin(), 1);
        }
        return digits;
    }
};