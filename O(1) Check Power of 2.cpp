/*
    Using O(1) time to check whether an integer n is a power of 2.

    Link: http://www.lintcode.com/en/problem/o1-check-power-of-2/

    Example: 
        For n=4, return true;
        For n=5, return false;

    Solution: Check the last digit is 1 or not in binary style.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/o1-check-power-of-2.cpp
*/

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        for (int i = 0; i < colors.size(); ++i) {
            if (colors[i] > 0) {
                int pos = colors[i] - 1;
                if (colors[pos] <= 0) {  // Bucket exists.
                    --colors[pos];
                    colors[i] = 0;
                }
                else {  // Init a new bucket.
                    colors[i] = colors[pos];
                    colors[pos] = -1;
                    --i;
                }
            }
        }

        for (int i = colors.size() - 1, pos = k - 1; pos >= 0; --pos) {
            while (colors[pos] < 0) {  // Reorder the color by count of each bucket.
                ++colors[pos];
                colors[i--] = pos + 1;
            }
        }
    }
};