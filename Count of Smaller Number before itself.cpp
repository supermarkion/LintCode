/*
    Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000). 
    For each element Ai in the array, count the number of element before this element Ai is smaller than it and 
    return count number array.
    Link: http://www.lintcode.com/en/problem/count-of-smaller-number-before-itself/
    Example: For array [1,2,7,8,5], return [0,1,2,3,2]
    Solution: After construct a Segment Tree, it is easyu to solve this problem, or perform a faster method based on
    sort first, then sort all the times during loop.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/count-of-smaller-number-before-itself.cpp
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        vector<int> sorted_A(A), places(A.size());
        sort(sorted_A.begin(), sorted_A.end());
        for (int i = 0; i < A.size(); i++) {
            // lower_bound: Returns an iterator pointing to the first element in the 
            // range [first,last) which does not compare less than val.
            places[i] = lower_bound(sorted_A.begin(), sorted_A.end(), A[i]) -
                        sorted_A.begin();
        }
        vector<int> bit(A.size() + 1), ans(A.size());
        for (int i = 0; i < A.size(); i++) {
            ans[i] = query(bit, places[i]);
            add(bit, places[i] + 1, 1);
        }
        return ans;
    }

private:
    void add(vector<int>& bit, int i, int val) {
        for (; i < bit.size(); i += lower_bit(i)) {
            bit[i] += val;
        }
    }
    
    int query(const vector<int> & bit, int i) {
        int sum = 0;
        for (; i > 0; i -= lower_bit(i)) {
            sum += bit[i];
        }
        return sum;
    }
    
    int lower_bit(int i) {
        return i & -i;
    }
};