/*
    On one line there are n houses. Give you an array of integer means the the position of each house.
    Now you need to pick k position to build k post office, so that the sum distance of each house to
    the nearest post office is the smallest. Return the least possible sum of all distances between
    each village and its nearest post office.
    Link: http://www.lintcode.com/en/problem/post-office-problem/
    Example: Given array a = [1,2,3,4,5], k = 2. return 3.
    Solution: This problem apply a special definition in the dynamic programming problem.
    Source:
        http://blog.csdn.net/find_my_dream/article/details/4931222
        https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/post-office-problem.cpp
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        // Write your code here
        const int n = A.size();
        if (A.empty() || k >= n) {
            return 0;
        }
        
        sort(A.begin(), A.end());
        
        vector<int> before_cost(n), after_cost(n);
        computeCost(A, &before_cost, &after_cost);
        
        vector<vector<int>> sum(2, vector<int>(A.size() + 1, INT_MAX));
        sum[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j <= n; j++) {
                for (int r = 1; r <= j; r++) {
                    if (sum[(i - 1) % 2][j - r] != INT_MAX) {
                        sum[i % 2][j] = min(sum[i % 2][j],
                                            sum[(i - 1) % 2][j - r] + 
                                            minCost(A, before_cost, after_cost,
                                            j - r, j - 1));
                    }
                }
            }
        }
        return sum[k % 2][n];
    }
    
    void computeCost(const vector<int>& A,
                     vector<int> *before_cost, vector<int> *after_cost) {
        const int n = A.size();
        for (int i = 1; i < n; ++i) {
            (*before_cost)[i] = (*before_cost)[i - 1] +
                                i * (A[i] - A[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            (*after_cost)[i] = (*after_cost)[i + 1] +
                               (n - 1 - i) * (A[i + 1] - A[i]);
        }
    }
    
    int minCost(const vector<int>& A,
                const vector<int> &before_cost, const vector<int> &after_cost,
                const int i, const int j) {
        // Min cost of building a post office between house (i, j).
        // This post office must be in median position.
        const int n = A.size();
        int mid = i + (j - i) / 2;
        int before_mid = before_cost[mid] -
                        (before_cost[i] + i * (A[mid] - A[i]));
        int after_mid = after_cost[mid] -
                        (after_cost[j] + (n - 1 - j) * (A[j] - A[mid]));
        return before_mid + after_mid;
    }    
    
};