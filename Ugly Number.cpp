/*
    Ugly number is a number that only have factors 3, 5 and 7. Design an algorithm to find the Kth ugly number. The first 5 ugly numbers are 3, 5, 7, 9, 15 ...
    
    Link: http://www.lintcode.com/en/problem/ugly-number/

    Example: If K=4, return 9.

    Solution: First of all, we use a priority queue to make all ugly number in the queue is ordered well. Then, we can easily
	to find that all ugly number is the multiply result of our factor numbers 3 5 and 7. However, we should avoid
	the situation that two same ugly number in the queue, for example 15 = 3 × 5 and 15 = 5 × 3. Therefore, we
	define a while loop to delete the duplicate ugly number.
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/ugly-number.cpp
*/

class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        long long ugly_number = 0;
        priority_queue<long long, vector<long long>, greater<long long>> heap;

        heap.emplace(1);
        for (int i = 0; i <= k; ++i) {
            ugly_number = heap.top();
            heap.pop();
            if (ugly_number % 3 == 0) {
                heap.emplace(ugly_number * 3);
            } else if (ugly_number % 5 == 0) {
                heap.emplace(ugly_number * 3);
                heap.emplace(ugly_number * 5);
            } else {
                heap.emplace(ugly_number * 3);
                heap.emplace(ugly_number * 5);
                heap.emplace(ugly_number * 7);
            }
        }
        return ugly_number;
    }
};