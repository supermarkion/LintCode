/*
    There is a fence with n posts, each post can be painted with one of the k colors.
	You have to paint all the posts such that no more than two adjacent fence posts have the same color.
	Return the total number of ways you can paint the fence.
    
    Link: http://www.lintcode.com/en/problem/paint-fence/

    Example: Given n=3, k=2 return 6
	      post 1,   post 2, post 3
	way1    0         0       1 
	way2    0         1       0
	way3    0         1       1
	way4    1         0       0
	way5    1         0       1
	way6    1         1       0

    Solution: None

    Source: None
*/

class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if (n == 0) {
        	return 0;
        }
        if (n == 1) {
        	return k;
        }
        vector<int> same(n + 1);
        vector<int> diff(n + 1);
    
        same[2] = k;
        diff[2] = k * (k - 1);

        for (int i = 3; i <= n; i++){
            same[i] = diff[i - 1];
            diff[i] = same[i - 1] * (k - 1) + diff[i - 1] * (k - 1);
        }
    
        return diff[n] + same[n];
    }
};