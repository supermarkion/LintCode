/*
    Given n non-negative integers representing an elevation map where the width of each bar is 1, 
    compute how much water it is able to trap after raining.
    Link: http://www.lintcode.com/en/problem/trapping-rain-water/
    Example: Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
    Solution: We find highest wall, and compute trapping water at left and right.
    Source: http://www.jiuzhang.com/solutions/trapping-rain-water/
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int maxHeight = 0, maxIndex;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
                maxIndex = i;
            }
        }
        
        int sum = 0;
        maxHeight = 0;
        for (int i = 0; i < maxIndex; i++) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        
        maxHeight = 0;
        for (int i = heights.size() - 1; i > maxIndex; i--) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        
        return sum;
    }
};