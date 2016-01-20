/*
    Given a unsorted array with integers, find the median of it. A median is the middle number of the array after it is sorted. 
	If there are even numbers in the array, return the N/2-th number after sorted.

    Link: http://www.lintcode.com/en/problem/median/

    Example: 
    	Given [4, 5, 1, 2, 3], return 3
		Given [7, 9, 4, 5], return 5

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/median.cpp
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        auto target = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), target, nums.end());
        // http://en.cppreference.com/w/cpp/algorithm/nth_element
        if (nums.size() % 2 == 1) {  // nums has odd number of elements.
            return *target;
        } else {  // nums has even number of elements.
            int x = *target;
            nth_element(nums.begin(), target - 1, nums.end());
            return *(target - 1);
        }
    }
};
