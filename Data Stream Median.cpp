/*
    Numbers keep coming, return the median of numbers at every time a new number added.

    Link: http://www.lintcode.com/en/problem/data-stream-median/

    Example: 
    	For numbers coming list: [1, 2, 3, 4, 5], return [1, 1, 2, 2, 3].
		For numbers coming list: [4, 5, 1, 3, 2, 6, 0], return [4, 4, 4, 3, 3, 3, 3].
		For numbers coming list: [2, 20, 100], return [2, 2, 20].

    Solution: In this problem, we will apply priority queue to sort stream, and return the median when it needs. The
	main point is using two queue, and when facing a new number, we make a decision on which queue should be add, then 
	when we face the size of two queues are not same, we change one elements in the larger queue to another.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/data-stream-median.cpp
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        
        // min_heap stores the larger half seen so far.
        priority_queue<int, vector<int>, greater<int>> min_heap;
        // max_heap stores the smaller half seen so far.
        priority_queue<int, vector<int>, less<int>> max_heap;

        vector<int> ans;
        for (const auto& num : nums) {
            if (max_heap.empty() || num > max_heap.top()) {
                min_heap.emplace(num);
                if (min_heap.size() > max_heap.size() + 1) {
                    max_heap.emplace(min_heap.top());
                    min_heap.pop();
                }
            } else {
                max_heap.emplace(num);
                if (max_heap.size() > min_heap.size()) {
                    min_heap.emplace(max_heap.top());
                    max_heap.pop();
                }
            }

            ans.emplace_back(min_heap.size() == max_heap.size() ?
                             max_heap.top() : min_heap.top());
        }

        return ans;
    }
};