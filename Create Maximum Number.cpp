/*
    Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length 
    k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return 
    an array of the k digits. You should try to optimize your time and space complexity.
    
    Link: http://www.lintcode.com/en/problem/create-maximum-number/

    Example: 
    	Given nums1 = [3, 4, 6, 5], nums2 = [9, 1, 2, 5, 8, 3], k = 5
		return [9, 8, 6, 5, 3]

		Given nums1 = [6, 7], nums2 = [6, 0, 4], k = 5
		return [6, 7, 6, 0, 4]

		Given nums1 = [3, 9], nums2 = [8, 9], k = 3
		return [9, 8, 9]
    
    Solution: None

    Source: https://leetcode.com/discuss/108207/c-greedy-method
*/

class Solution {
public:
    /**
     * @param nums1 an integer array of length m with digits 0-9
     * @param nums2 an integer array of length n with digits 0-9
     * @param k an integer and k <= m + n
     * @return an integer array
     */
    vector<int> getMaxArray(vector<int>& nums, int k){
        vector<int> ans;
        int len = nums.size();
        for (int i = 0, j = 0; i < len; ++i) 
        {
            while (j > 0 && len - i + j > k && ans[j - 1] < nums[i])
            {
                ans.pop_back();
                --j;
            }
            if (j < k) 
            {
                ans.push_back(nums[i]);
                ++j;
            }
        }
        return ans;
    }
    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        while (i < len1 && j < len2 && nums1[i] == nums2[j])
        {
            ++i;
            ++j;
        }
        if (j == len2 || (i < len1 && nums1[i] > nums2[j]))
        {
            return true;
        }
        return false;
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> ans;
        for (int i = 0, j = 0, m = 0;i < len1 || j < len2;) 
        {
            ans.push_back((greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++]));
        }
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 < len2)
        {
            return maxNumber(nums2, nums1, k);
        }
        vector<int> ans;
        for (int i = max(0, k - len1); i <= min(k, len2); ++i)
        {
            vector<int> c2 = getMaxArray(nums2, i);
            vector<int> c1 = getMaxArray(nums1, k - i);
            vector<int> c = merge(c1, c2);
            if (ans.empty() || greater(c, 0, ans, 0))
            {
                ans = c;
            }
        }
        return ans;
    }
};