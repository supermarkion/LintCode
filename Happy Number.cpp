/*
    Write an algorithm to determine if a number is happy. A happy number is a number defined by
    the following process: Starting with any positive integer, replace the number by the sum of
    the squares of its digits, and repeat the process until the number equals 1 (where it will 
    stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which 
    this process ends in 1 are happy numbers.

    Link: http://www.lintcode.com/en/problem/happy-number/
    Example: 19 is a happy number
    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1

    Solution: use a set to save loop of process of construction happy number, if repeat, we break
    and return false.
    Source: http://www.jiuzhang.com/solutions/happy-number/
*/

class Solution {
public:
    
    int getNextHappy(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        if (!n || n < 0) {
            return false;
        }
        unordered_set<int> hash;
        while (n != 1) {
            if (hash.find(n) != hash.end()) {
                return false;
            }
            hash.emplace(n);
            n = getNextHappy(n);
        }
        return true;
    }
};