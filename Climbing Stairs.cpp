/*
    You are climbing a stair case. It takes n steps to reach to the top. Each time you can either climb 1 or 2 steps. 
    In how many distinct ways can you climb to the top?

    Link: http://www.lintcode.com/en/problem/climbing-stairs/

    Example: Given an example n=3 , 1+1+1=2+1=1+2=3, return 3

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/climbing-stairs.cpp
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        vector<int> steps(3, 0);
        steps[0] = 1;
        steps[1] = 1;
        for (int i = 2; i <= n; ++i) {
            steps[i % 3] = steps[(i - 1) % 3] + steps[(i - 2) % 3];
        }
        return steps[n % 3];
    }
};
