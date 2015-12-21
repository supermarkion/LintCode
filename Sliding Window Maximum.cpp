/*
    Given an array of n integer with duplicate number, and a moving window(size k), move the window 
    at each iteration from the start of the array, find the maximum number inside the window at each moving.

    Link: http://www.lintcode.com/en/problem/sliding-window-maximum/

    Example: 
    For array [1, 2, 7, 7, 8], moving window size k = 3. return [7, 7, 8]
		At first the window is at the start of the array like this
		[|1, 2, 7| ,7, 8] , return the maximum 7;

		then the window move one step forward.
		[1, |2, 7 ,7|, 8], return the maximum 7;

		then the window move one step forward again.
		[1, 2, |7, 7, 8|], return the maximum 8;

    Solution: Given an array of n integer with duplicate number, and a moving window(size k), move the window at each
	iteration from the start of the array, find the maximum number inside the window at each moving. In the problem, 
	we use a deque, and update them to get the maximum values during the sliding process.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C++/sliding-window-maximum.cpp
*/

 class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        const int n = nums.size();
        deque<int> q;
        vector<int> max_numbers;

        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.emplace_back(i);
        }

        for (int i = k; i < n; ++i) {
            max_numbers.emplace_back(nums[q.front()]);

            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            q.emplace_back(i);
        }

        if (!q.empty()) {
            max_numbers.emplace_back(nums[q.front()]);
        }

        return max_numbers;
    }
};
