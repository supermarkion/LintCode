/*
    Given an integer array, find a subarray where the sum of numbers is between two given interval.
    Your code should return the number of possible answer. (The element in the array should be positive)
    Link: http://www.lintcode.com/en/problem/subarray-sum-ii/
    Example: Given [1,2,3,4] and interval = [1,3], return 4. The possible answers are:
        [0, 0]
        [0, 1]
        [1, 1]
        [2, 2]

    Solution: The key point to speed up the count solution number. We firstly sum all number to 
    its past, and then we can use the new updated list as a range, and then the number can be use
    to compare with interval to get solution number.
    Source: None
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        // Write your code here
        int len = A.size();
        for (int i = 1; i < len; ++i) {
            A[i] += A[i - 1];
        }
        sort(A.begin(), A.end());
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] >= start && A[i] <= end) {
                cnt++;
            }
            int l = A[i] - end;
            int r = A[i] - start;
            cnt += find(A, len, r + 1) - find(A, len, l);
        }
        return cnt;
    }
    int find(vector<int>& A, int len, int value) {
        if (A[len - 1] < value) {
            return len;
        }
        int l = 0, r = len - 1, ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (value <= A[mid]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};