/*
    Given a permutation which may contain repeated numbers, find its index in all 
    the permutations of these numbers, which are ordered in lexicographical order. 
    The index begins at 1.
    Link: http://www.lintcode.com/en/problem/permutation-index-ii/
    Example: Given the permutation [1, 4, 2, 2], return 3.
    Solution: The key point to compute how many permutation had already be 
    constructed based on current situation.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/next-permutation.cpp
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        long long index = 1;
        // Position 1 is paired with factor 0 and so is skipped.
        int position = 2;
        long long factor = 1;
        map<int, int> number_to_count;
        ++number_to_count[A.back()];
        // Type conversions by static_cast
        for (int i = static_cast<int>(A.size()) - 2; i >= 0; --i) {
            ++number_to_count[A[i]];
            for (const auto& kvp : number_to_count) {
                if (kvp.first >= A[i]) {
                    break;
                } 
                index += factor * kvp.second / number_to_count[A[i]];
            }
            factor = factor * position / number_to_count[A[i]];
            ++position;
        }
        return index;
    }
};