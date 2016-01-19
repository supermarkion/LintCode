/*
    Given a string s, cut s into some substrings such that every substring is a palindrome. Return the minimum cuts needed 
    for a palindrome partitioning of s.

    Link: http://www.lintcode.com/en/problem/palindrome-partitioning-ii/

    Example: Given s = "aab", Return 1 since the palindrome partitioning ["aa", "b"] could be produced using 1 cut.

    Solution: In this problem, we should construct all kinds of sub-string in the given word, and make a decision it is a
    palindrome or not. If it is, then add it into result list. We can solve it by dfs method. we face the cutting questions, 
    we set the maximum of cut value is the size of word (if we divided this word into each character, it must be palindrome).

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/backpack-ii.cpp
*/

 class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        vector<deque<bool>> is_palindrome(s.size(), deque<bool>(s.size(), false));
        vector<int> T(s.size() + 1);
        iota(T.rbegin(), T.rend(), -1); // assign the increasing values in this array.
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j] && (j - i < 2 || is_palindrome[i + 1][j - 1])) {
                    is_palindrome[i][j] = true;
                    T[i] = min(T[i], 1 + T[j + 1]);
                }
            }
        }
        return T[0];
    }
};

