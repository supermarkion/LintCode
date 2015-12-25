/*
    Given string A representative a positive integer which has N digits, remove any 
    k digits of the number, the remaining digits are arranged according to the original 
    order to become a new positive integer. Find the smallest integer after remove k digits.
	N <= 240 and k <= N,

    Link: http://www.lintcode.com/en/problem/delete-digits/

    Example:
    	Given an integer A = "178542", k = 4
		return a string "12"

    Solution: Use a stack to save process, which keep its original ordering.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/delete-digits.cpp
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        const auto len = A.size();

        // Handle boundary case
        if (len == k) {
            return "0";
        }

        // If a digit is greater than next one, delete it.
        stack<char> s;
        for (auto i = 0; i < len; ++i) {
            while (k > 0 && !s.empty() && s.top() > A[i]) {
                s.pop();
                --k;
            }
            s.emplace(A[i]);
        }

        // If all digits are increasingly sorted, delete last.
        while (k > 0) {
            s.pop();
            --k;
        }

        // Assemble the answer in reverse order
        string ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());

        // Strip all leading '0'
        auto i = 0;
        for (; i < ans.length() && ans[i] == '0'; ++i);
        ans = ans.substr(i);

        // Handle boundary case
        if (ans.length() == 0) {
            return "0";
        }

        return ans;
    }
};
