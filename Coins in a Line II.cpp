/*
    There are n coins with different value in a line. Two players take turns to take one or two coins from left 
    side until there are no more coins left. The player who take the coins with the most value wins.
	Could you please decide the first player will win or lose?

    Link: http://www.lintcode.com/en/problem/coins-in-a-line-ii/
    Example: 
		Given values array A = [1,2,2], return true.
		Given A = [1,2,4], return false.
    Solution: It should be sovled by Minmax, but the sample use dp.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/coins-in-a-line-ii.cpp
*/

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        vector<int> P(5);
        int sum = 0;
        for (int i = values.size() - 1; i >= 0; i--) {
            sum += values[i];
            const int a = i + 1 < values.size() ? values[i + 1] : 0;
            const int b = i + 2 < values.size() ? P[(i + 2) % 5] : 0;
            const int c = i + 3 < values.size() ? P[(i + 3) % 5] : 0;
            const int d = i + 4 < values.size() ? P[(i + 4) % 5] : 0;
            P[i % 5] = max(values[i] + min(b, c), values[i] + a + min(c, d));
        }
        return P[0] > sum - P[0];
    }
};