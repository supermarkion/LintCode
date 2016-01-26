/*
    Count the number of k's between 0 and n. k can be 0 - 9.
    
    Link: http://www.lintcode.com/en/problem/digit-counts/

    Example: if n=12, k=1 in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], we have FIVE 1's (1, 10, 11, 12)

    Solution: In this problem, it has three main principle:
		• when current digit is less than target number, the repeat possible is higherdigital × base
		• when current digit is greater than target number, the repeat possible is (higherdigital + 1) × base
		• when they are equal, we add higherdigital × base + lower + 1
    
    Source: None
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count = 0;
        
        for (int i = 0; i <= n; i++) {
            count += getCount(k, i);
        }
        
        return count;
    }
    
    int getCount(int k, int n) {
        int count = 0;
        
        if (n == 0) {
            return k == 0 ? 1 : count;
        }
        
        while (n > 0) {
            int lastDigit = n % 10;
            if (lastDigit == k) {
                count++;
            }
            n /= 10;
        }
        
        return count;
    }
};