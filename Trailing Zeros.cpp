/*
    Write an algorithm which computes the number of trailing zeros in n factorial.
    
    Link: http://www.lintcode.com/en/problem/trailing-zeros/

    Example: 11! = 39916800, so the out should be 2

    Solution: Based on the definition of factorial, it is easy to notice that quantity of 5 of the input number can decide
	how many 0 at the trialling (one pair of 2 and 5 can contribute to a 10, but the number of 2 is much more -
	each even number have a 2). Then, we just need to compute how many 5 in the given number.
    
    Source: None
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        // write your code here
        if ( n < 0) {
            return -1;
        }
        long long count = 0;
        for (; n > 0; n /= 5) {
            count += (n / 5) ;
        }
        return count;
    }
};
