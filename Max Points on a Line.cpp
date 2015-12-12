/*
    Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

    Link: http://www.lintcode.com/en/problem/max-points-on-a-line/
    
    Example: 
    Given 4 points: (1,2), (3,6), (0,0), (1,3).
	The maximum number is 3.

    Solution: if two points have same slope, and start from same points (start or end), we can know they
    located in the same line, and use a map to save their relationships. Note that, the points locats
  	on the same vertical line or horizel line should also be considered.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/max-points-on-a-line.cpp
*/

#include <cfloat>

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int max_points = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> slopes;
            const auto& start = points[i];
            int same = 1;
            
            for (int j = i + 1; j < points.size(); ++j) {
                const auto& end = points[j];
                if (start.x == end.x && start.y == end.y) {
                    ++same;
                } else {
                    double slope = DBL_MAX; // Maximum finite representable floating-point number
                    if (start.x - end.x != 0) {
                        slope = (start.y - end.y) * 1.0 / (start.x - end.x);
                    }
                    slopes[slope]++;
                }
            }
            
            int current_max = same;
            for (const auto& kvp : slopes) {
                current_max = max(current_max, kvp.second + same);
            }
            max_points = max(max_points, current_max);
        }
        
        return max_points;
    }
};