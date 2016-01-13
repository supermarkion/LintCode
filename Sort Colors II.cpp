/*
    Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same 
    color are adjacent, with the colors in the order 1, 2, ... k.

    Link: http://www.lintcode.com/en/problem/sort-colors-ii/

    Example: Given colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4].

    Solution: Perform bucket sort method.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/sort-colors-ii.cpp
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