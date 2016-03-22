/*
    Write a program to check whether a given number is an ugly number`. Ugly numbers are positive numbers 
    whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it 
    includes another prime factor 7.
    
    Link: http://www.lintcode.com/en/problem/ugly-number/

    Example: 
    	Given num = 8 return true
		Given num = 14 return false

    Solution: None

    Source: None
*/

class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        if (num <= 0) {
        	return false; 	
        } 
        if (num == 1) {
        	return true; 	
        } 
          
        while (num >= 2 && num % 2 == 0) {
        	num /= 2;	
        }  
        while (num >= 3 && num % 3 == 0) {
        	num /= 3; 	
        } 
        while (num >= 5 && num % 5 == 0) {
        	num /= 5;	
        }  
          
        return num == 1;
    }
};