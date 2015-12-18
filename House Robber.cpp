/*
    You are a professional robber planning to rob houses along a street. Each house has a certain amount 
    of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses 
    have security system connected and it will automatically contact the police if two adjacent houses were 
    broken into on the same night.
    Given a list of non-negative integers representing the amount of money of each house, determine the 
    maximum amount of money you can rob tonight without alerting the police.
    Link: http://www.lintcode.com/en/problem/house-robber/
    Example: Given [3, 8, 4], return 8.
    Solution: When we meet a house, we have to decision on robber its previous two or three houses to 
    achieve maximum values
    Source: None
*/

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        int n = A.size();
        long * res = new long[n];
        long ans = 0;
        if (A.empty()) {
            return 0;
        }
        if (n >= 1) {
            res[0] = A[0];
        }
        if (n >= 2) {
            res[1] = max(A[0], A[1]);
        }
        if (n >= 3) {
            res[2] = max(A[0] + A[2], A[1]);
        }
        if (n > 2) {
            for (int i = 3; i < n; i++) {
                res[i] = max(res[i - 3], res[i - 2]) + A[i];
            }
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, res[i]);
        }
        delete res;
        return ans;
    }
};