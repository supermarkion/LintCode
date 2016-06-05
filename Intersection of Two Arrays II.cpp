/*
    Given two arrays, write a function to compute their intersection.

    Link: http://www.lintcode.com/en/problem/intersection-of-two-arrays-ii/

    Example: 
		Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

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
        unordered_map<int, int> map1;
        for (auto num : nums1) {
            if (map1.count(num) == 1) {
                map1[num] = map1[num] + 1;
            } else {
                map1[num] = 1;
            }
        }

        unordered_map<int, int> map2;
        for (auto num : nums2) {
            if (map2.count(num) == 1) {
                map2[num] = map2[num] + 1;
            } else {
                map2[num] = 1;
            }
        }
        
        vector<int> nums;
        for(unordered_map<int, int>::iterator entery = map1.begin(); entery != map1.end(); entery++) {
            int times = entery -> second;
            if (map2.count(entery -> first)) {
                times = min(times, map2[entery -> first]);
            } else {
                times = 0;
            }
            for (int i = 0; i < times; i++) {
                nums.push_back(entery -> first);
            }
        }
        
        return nums;
    }
};