/*
    Write a program to find the nth super ugly number. Super ugly numbers are positive numbers whose all 
    prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 
    19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of 
    size 4.
   
	Link: http://www.lintcode.com/en/problem/super-ugly-number/

    Example: 
	    Given n = 6, primes = [2, 7, 13, 19] return 13
	
    Solution: None

    Source: None
*/

class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        vector<int> result(n,INT_MAX);
        result[0] = 1;
        vector<int> index(primes.size(), 0);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < primes.size(); j++) 
            {
            	result[i] = min(result[i], primes[j] * result[index[j]]);	
            }
            
            for (int j = 0; j < primes.size(); j++)
            {
                if (primes[j] * result[index[j]] == result[i])
                {
                	index[j]++;	
                }
            }
        }
        return result[n - 1];
    }
};