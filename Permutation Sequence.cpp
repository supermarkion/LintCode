/*
    Given n and k, return the k-th permutation sequence.
    Link: http://www.lintcode.com/en/problem/permutation-sequence/#
    Example: For n = 3, all permutations are listed as follows:
    	"123"
		"132"
		"213"
		"231"
		"312"
		"321"
    Solution: Given n and k, return the number of k permutation sequence. We should simulation the process on how construct permutation.
    Source: None
*/

 class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
       if (n <= 0 && k <= 0) {
           return "";
       }
       int fact = 1;
       vector<int> nums;
       for (int i = 1; i <= n; i++) {
           fact *= i;
           nums.emplace_back(i);
       }
       stringstream ss;
       for (int i = n; i >= 1; i--) {
           fact /= i;
           int rank = (k - 1) / fact;
           k = (k - 1) % fact + 1;
           ss << nums[rank];
           nums.erase(nums.begin() + rank);
       }
       return ss.str();
    }
};