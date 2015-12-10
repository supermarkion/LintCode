/*
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses..
	Link: http://www.lintcode.com/en/problem/generate-parentheses/
	Example: Given n = 3, a solution set is: "((()))", "(()())", "(())()", "()(())", "()()()"
	Solution: perform recursion, and update a temp string named sample, note that, after once successful
	push_back to finial result, we will cancel last update action on sample by resize this string.
*/

class Solution {
public:
    void CombinationPar(vector<string>& result, string& sample,
            int deep, int n, int leftNum, int rightNum) {  
        if(deep == 2 * n) {  
           result.push_back(sample);         // when finish this time
           return;  
        }  
        if(leftNum < n) {                    // when ( not finish
            sample.push_back('(');  
            CombinationPar(result, sample, deep + 1, n, leftNum + 1, rightNum);  
            sample.resize(sample.size() - 1);// leave left to size - 1  
        }
        if(rightNum < leftNum) {             // when ) not finish
            sample.push_back(')');  
            CombinationPar(result, sample, deep + 1, n, leftNum, rightNum + 1);  
            sample.resize(sample.size() - 1);  
        }  
    }

    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> result;
        string sample;
        if (n !=0 ) {
            CombinationPar(result, sample, 0, n, 0, 0);
        }
        return result;
    }
    
};