/*
    Write a method to replace all spaces in a string with %20. The string is given in a characters
    array, you can assume it has enough space for replacement and you are given the true length of 
    the string. You code should also return the new length of the string after replacement.

    Link: http://www.lintcode.com/en/problem/space-replacement/
    Example: Given "Mr John Smith", length = 13.
    The string after replacement should be "Mr%20John%20Smith".

    Solution: firstly, count how many empty space in original string, and then combine them.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/space-replacement.cpp
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        const array<char, 3> to{'%', '2', '0'};
        
        int space_count = 0;
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ') {
                ++space_count;
            }
        }
        
        const int new_length = length +
                               (static_cast<int>(to.size()) - 1) * space_count;
        for (int i = length - 1, j = new_length - 1; i >= 0; --i) {
            if (string[i] == ' ') {
                j -= to.size();
                // cbegin: Returns a const_iterator pointing to the first element
                // in the array container.
                copy(to.cbegin(), to.cend(), string + j + 1);
            } else {
                string[j--] = string[i];
            }
        }
        return new_length;
    }
};  