/*
    Find K-th largest element in an array.

    Link: http://www.lintcode.com/en/problem/kth-largest-element/

    Example: In array [9,3,2,4,8], the 3rd largest element is 4.
			 In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.

    Solution: The easiest solution is to choose a random pivot, which yields almost certain linear time. Deterministically,
	one can use median-of-3 pivot strategy (as in the quicksort), which yields linear performance on partially
	sorted data, as is common in the real world. However, contrived sequences can still cause worst-case com-
	plexity; David Musser describes a "median-of-3 killer" sequence that allows an attack against that strategy,
	which was one motivation for his introselect algorithm.
		To sum up, we should sort this array firstly, but only use the pivot to divided the array to two sub-array.
	If the pivot is our target ordered index, we return, or reduce size of sort.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/kth-largest-element.cpp
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here.
        int left = 0, right = nums.size() - 1;
        default_random_engine gen((random_device())());
        while (left <= right) {
            // Generates a random int in [left, right].
            uniform_int_distribution<int> dis(left, right);
            int pivot_idx = dis(gen);
            int new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, nums);
            if (new_pivot_idx == k - 1) {
                return nums[new_pivot_idx];
            } else if (new_pivot_idx > k - 1) {
                right = new_pivot_idx - 1;
            } else {  // new_pivot_idx < k - 1.
                left = new_pivot_idx + 1;
            }
        }
    }

    // Partition nums[left : right] around pivot_idx, returns the new index of the
    // pivot, new_pivot_idx, after partition. After partitioning,
    // nums[left : new_pivot_idx - 1] contains elements that are greater than the
    // pivot, and nums[new_pivot_idx + 1 : right] contains elements that are less
    // than the pivot.
    int PartitionAroundPivot(int left, int right, int pivot_idx, vector<int>& nums) {
        int pivot_value = nums[pivot_idx];
        int new_pivot_idx = left;
        swap(nums[pivot_idx], nums[right]);
        for (int i = left; i < right; ++i) {
            if (nums[i] > pivot_value) {
                swap(nums[i], nums[new_pivot_idx++]);
            }
        }
        swap(nums[right], nums[new_pivot_idx]);
        return new_pivot_idx;
    }
};