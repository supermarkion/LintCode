/*
    The count-and-say sequence is the sequence of integers beginning as follows:
    1, 11, 21, 1211, 111221, ...
    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.
    Given an integer n, generate the nth sequence.

    Link: http://www.lintcode.com/en/problem/count-and-say/
    Example: Given n = 5, return "111221".
    Solution: When we meet two neighboor digit is small, we add count, once different,
    we add count to string.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/count-and-say.cpp
*/

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        string seq{"1"};
        for (int i = 0; i < n - 1; ++i) {
            seq = getNext(seq);
        }
        return seq;
    }
    
    string getNext(const string& seq) {
        stringstream next_seq;
        for (int i = 0; i < seq.length(); i++) {
            int cnt = 1;
            while (i < seq.length() - 1 && seq[i] == seq[i + 1]) {
                cnt++, i++;
            }
            next_seq << cnt << seq[i];
        }
        return next_seq.str();
    }
};