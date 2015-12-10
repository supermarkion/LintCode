/*
	Given two strings, write a method to decide if one is a permutation of the other.
	Link: http://www.lintcode.com/en/problem/string-permutation/
	Example: abcd is a permutation of bcad, but abbe is not a permutation of abe
	Solution: sort first, then compare equal or not
*/

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());
        return A == B;
    }
};