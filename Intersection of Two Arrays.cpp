/*
    Given two arrays, write a function to compute their intersection.

    Link: http://www.lintcode.com/en/problem/intersection-of-two-arrays/

    Example: 
		Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

    Solution: None

    Source: None
*/

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        unordered_map<int, int> map;
        for (auto num : nums1) {
            map[num] = 1;
        }

        int len = 0;
        for (auto num : nums2) {
            if (map.count(num) == 1 && map[num] == 1) {
                map[num] = 2;
                ++len;
            }
        }

        vector<int> nums;
        int i = 0;
        
        for (unordered_map<int, int>::iterator i = map.begin(); i != map.end(); i++) {
             if (i -> second == 2) {
                 nums.push_back(i -> first);
             }
        }
        return nums;
    }
};