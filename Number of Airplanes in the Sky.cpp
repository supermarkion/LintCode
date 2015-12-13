/*
    Given an interval list which are flying and landing time of the flight. How many airplanes
    are on the sky at most?

    Link: http://www.lintcode.com/en/problem/number-of-airplanes-in-the-sky/
    Example: For interval list [[1,10],[2,3],[5,8],[4,7]], return 3
    Solution: First of all, we sort the intervals at their start. Then, we update the last interval, when we meet overlapping,
    we set the last end to maximum of current end or last end.
    Source: 
    https://github.com/kamyu104/LintCode/blob/master/C++/merge-intervals.cpp
    https://github.com/kamyu104/LintCode/blob/master/C++/number-of-airplanes-in-the-sky.cpp
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        int maxPlane = 0;
        int plane = 0;
        
        vector<int> starts, ends;
        for (const auto& airplane : airplanes) {
            starts.emplace_back(airplane.start);
            ends.emplace_back(airplane.end);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int s = 0, e = 0;
        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                plane++;
                maxPlane = max(maxPlane, plane);
                s++;
            } else {
                plane--;
                e++;
            }
        }
        return maxPlane;
    }
};