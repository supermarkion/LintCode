/*
    Given a non-overlapping interval list which is sorted by start point. Insert a new interval into it, make sure the list 
    is still in order and non-overlapping (merge intervals if necessary).
    
    Link: http://www.lintcode.com/en/problem/insert-interval/

    Example: 
    	Insert [2, 5] into [[1,2], [5,9]], we get [[1,9]].
		Insert [3, 4] into [[1,2], [5,9]], we get [[1,2], [3,4], [5,9]].

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/insert-interval.cpp
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
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        size_t i = 0;
        vector<Interval> result;
        // Insert intervals appeared before newInterval.
        while (i < intervals.size() && newInterval.start > intervals[i].end) {
            result.emplace_back(intervals[i++]);
        }

        // Merge intervals that overlap with newInterval.
        while (i < intervals.size() && newInterval.end >= intervals[i].start) {
            newInterval = {min(newInterval.start, intervals[i].start),
                max(newInterval.end, intervals[i].end)};
            ++i;
        }
        result.emplace_back(newInterval);

        // Insert intervals appearing after newInterval.
        result.insert(result.end(), intervals.cbegin() + i, intervals.cend());
        // cbegin and cend make sure container not modifty the elements
        return result;
    }
};