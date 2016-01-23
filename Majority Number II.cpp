/*
    Given an array of integers, the majority number is the number that occurs more than 1/3 of the size of the array.
    
    Link: http://www.lintcode.com/en/problem/majority-number-ii/

    Example: Given [1, 2, 1, 2, 1, 3, 3], return 1.

    Solution: Given an array of integers, the majority number is the number that occurs more than of the size of the 3
	array. Therefore, in this problem, we can update 3 candidate numbers, and use their count to compute which one 
	is majority number.
    
    Source: http://www.lintcode.com/en/problem/majority-number-ii/
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        const int k = 3;
        unordered_map<int, int> hash;

        for (const auto& i : nums) {
            ++hash[i];
            // Detecting k items in hash, at least one of them must have exactly
            // one in it. We will discard those k items by one for each.
            // This action keeps the same mojority numbers in the remaining numbers.
            // Because if x / n  > 1 / k is true, then (x - 1) / (n - k) > 1 / k is also true.
            if (hash.size() == k) {
                auto it = hash.begin();
                while (it != hash.end()) {
                    if (--(it->second) == 0) {
                        hash.erase(it++);
                    } else {
                        ++it;
                    }
                }
            }
        }

        // Resets hash for the following counting.
        for (auto& it : hash) {
            it.second = 0;
        }

        // Counts the occurrence of each candidate word.
        for (const auto& i : nums) {
            auto it = hash.find(i);
            if (it != hash.end()) {
                ++it->second;
            }
        }

        // Selects the integer which occurs > n / k times.
        vector<int> ret;
        for (const pair<int, int>& it : hash) {
            if (it.second > static_cast<double>(nums.size()) / k) {
                ret.emplace_back(it.first);
            }
        }

        return ret[0];
    }
};