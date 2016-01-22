/*
    Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique 
    quadruplets in the array which gives the sum of target.

    Link: http://www.lintcode.com/en/problem/4sum/

    Example: 
    	Given array S = {1 0 -1 0 -2 2}, and target = 0. A solution set is:
		(-1, 0, 0, 1)
		(-2, -1, 1, 2)
		(-2, 0, 0, 2)

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/4-sum.cpp
*/

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end()); // Make sure quadruplets are in non-descending orders.
        unordered_map<int, vector<vector<size_t>>> two_sum; // two_sum saves "sum to (i, j) pairs, which i < j."
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                bool have_duplicate = false;
                for (const auto& vec : two_sum[nums[i] + nums[j]]) {
                    if (nums[vec.front()] == nums[i]) {  // Duplicated.
                        have_duplicate = true;
                        break;
                    }
                }
                if (!have_duplicate) {  // Not duplicated
                    vector<size_t> new_vec = {i, j};
                    two_sum[nums[i] + nums[j]].emplace_back(move(new_vec));
                }
            }
        }

        unordered_set<string> answers; // Use hash to filter duplicated.
        vector<vector<int>> res;
        for (size_t i = 2; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                auto it = two_sum.find(target - nums[i] - nums[j]);
                if (it != two_sum.end()) {
                    for (const auto& vec : it->second) {
                        if (i > vec.back()) {  // {vec.front() < vec.back() < i < j}
                            vector<int> candidate = {nums[vec.front()], nums[vec.back()], nums[i], nums[j]};
                            if (answers.emplace(join_vector(candidate)).second) {  // Not duplicated.
                                res.emplace_back(move(candidate)); // Add to answers.
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

    // Hash vector to string.
    string join_vector(const vector<int>& nums) {
        string ret;
        for (int n : nums) {
            ret += to_string(n);
            ret += ' ';
        }
        return ret;
    }
};
