/*
    Given a string which contains only letters. Sort it by lower case first and upper case second.
    
    Link: http://www.lintcode.com/en/problem/sort-letters-by-case/

    Example: For "abAcD", a reasonable answer is "acbAD"

    Solution: Partition part method.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/sort-letters-by-case.cpp
*/

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int left = 0, right = letters.size() - 1;

        while (left < right) {
            if (isupper(letters[left])) {
                swap(letters[left], letters[right]);
                --right;
            } else {
                ++left;
            }
        }
    }
};
