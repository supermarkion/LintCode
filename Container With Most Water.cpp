/*
    Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
    n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two 
    lines, which together with x-axis forms a container, such that the container contains the most water.
    Link: http://www.lintcode.com/en/problem/container-with-most-water/
    Example: Given [1,3,2], the max area of the container is 2.
    Solution: Perform two pointers method to solve this problem, remember, many two pointer solution start
    at begin and end of line.
    Source: http://www.lintcode.com/en/problem/container-with-most-water/
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        if (heights.empty() || heights.size() == 1) {
            return 0;
        }
        int left = 0, right = heights.size() - 1, maxArea = min(heights[left], heights[right]) * (right - left);
        while (left < right) {
            maxArea = max(maxArea, min(heights[left], heights[right]) * (right - left));
            if (heights[left] > heights[right]) { // right is weak, find new right
                right--;
            } else if (heights[left] < heights[right]) { // left is weak, find new left
                left++;
            } else {
                left++;
                right--;
            }
        }
        return maxArea;
    }
};