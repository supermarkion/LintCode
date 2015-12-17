/*
    Given a collection of intervals, merge all overlapping intervals.
    Link: http://www.lintcode.com/en/problem/merge-intervals/
    Example: Given intervals => merged intervals:
	[                     [
	  [1, 3],               [1, 6],
	  [2, 6],      =>       [8, 10],
	  [8, 10],              [15, 18]
	  [15, 18]            ]
	]
    Solution: Typical sort by container, and loop array.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/merge-intervals.cpp
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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if (intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(),
        [](const Interval& a, const Interval& b) {
            return a.start < b.start;               
        }); // sort from low to high
        
        vector<Interval> result = {intervals[0]}; // add smallest intervals
        for (int i = 1; i < intervals.size(); i++) {
            Interval& prev = result.back();
            if (intervals[i].start <= prev.end) {
                prev.end = max(prev.end, intervals[i].end);
            } else {
                result.emplace_back(intervals[i]);
            }
        }
        return result;
    }
};