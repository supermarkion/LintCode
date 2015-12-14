/*
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    Link: http://www.lintcode.com/en/problem/valid-parentheses/
    Example: The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
    Solution: Update a stack to delete or add new coming char into stack. In fact, we should also constider of that
    new coming char which not belong to "(){}[]".
    Source: None
*/

 class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        if (s.empty()) {
            return true;
        }
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')' && st.top() == '(') {
                st.pop();
            } else if (s[i] == ']' && st.top() == '[') {
                st.pop();
            } else if (s[i] == '}' && st.top() == '{') {
                st.pop();
            } else {
                st.emplace(s[i]);
            }
        }
        return st.empty() ? true : false;
    }
};