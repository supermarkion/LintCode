/*
    Given 2*n + 2 numbers, every numbers occurs twice except two, find them.

    Link: http://www.lintcode.com/en/problem/single-number-iii/

    Example: Given [1,2,2,3,4,4,5,3] return 1 and 5

    Solution: The two numbers that appear only once must differ at some bit, this is how we can distinguish between them.
	Otherwise, they will be one of the duplicate numbers. Let’s say the at the ith bit, the two desired numbers
	differ from each other. which means one number has bit i equaling: 0, the other number has bit i equaling
	1. Thus, all the numbers can be partitioned into two groups according to their bits at location i. the first
	group consists of all numbers whose bits at i is 0. the second group consists of all numbers whose bits at i
	is 1. Notice that, if a duplicate number has bit i as 0, then, two copies of it will belong to the first group.
	Similarly, if a duplicate number has bit i as 1, then, two copies of it will belong to the second group. by
	XoRing all numbers in the first group, we can get the first number. by XoRing all numbers in the second
	group, we can get the second number.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/single-number-iii.cpp
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        // Xor all the elements to get x ^ y.
        int x_xor_y = 0;
        for (const auto& i : A) {
            x_xor_y ^= i;
        }

        // Get the last bit where 1 occurs.
        const auto bit = x_xor_y & ~(x_xor_y - 1);

        // Get the subset of A where the number has the bit.
        // The subset only contains one of the two integers, call it x.
        // Xor all the elements in the subset to get x.
        int x = 0;
        for (const auto& i : A) {
            if (i & bit) {
                x ^= i;
            }
        }

        return {x, x_xor_y ^ x};
    }
};