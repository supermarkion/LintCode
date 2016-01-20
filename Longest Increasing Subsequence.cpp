/*
    Given a sequence of integers, find the longest increasing subsequence (LIS). You code should return the length of the LIS.

    Link: http://www.lintcode.com/en/problem/longest-increasing-subsequence/

    Example: 
    	For [5, 4, 1, 2, 3], the LIS  is [1, 2, 3], return 3
		For [4, 2, 4, 5, 3, 7], the LIS is [4, 4, 5, 7], return 4

    Solution: Given a sequence of integers, find the longest increasing subsequence (LIS). In order to solve this problem
	by dynamic programming method, we should know that the dp list save the information that the number in the current 
	index have the LIS value. In order to finish that, we should compare current number and its previous numbers. 
	In order to speed up this process, we use a dp list to save the previous LIS values.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/longest-increasing-subsequence.cpp
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        vector<int> LIS;

        for (const auto& i : nums) {
            insert(&LIS, i);
        }

        return LIS.size();
    }

private:
    void insert(vector<int> *LIS, const int target) {
        int left = 0, right = LIS->size() - 1;
        auto comp = [](int x, int target) { return x > target; };

        // Find the first index "left" which satisfies LIS[left] > target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (comp((*LIS)[mid], target)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // If not found, append the target.
        if (left == LIS->size()) {
            LIS->emplace_back(target);
        } else {
            (*LIS)[left] = target;
        }
    }
};
