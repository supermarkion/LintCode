/*
    For an array A, if i < j, and A [i] > A [j], called (A [i], A [j]) is a reverse pair. return total of reverse pairs in A.
    
    Link: http://www.lintcode.com/en/problem/reverse-pairs/

    Example: 
    	Given A = [2, 4, 1, 3, 5] , (2, 1), (4, 1), (4, 3) are reverse pairs. return 3

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/reverse-pairs.cpp
*/

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        long long count = 0;
        vector<pair<int, int>> num_idxs;
        for (int i = 0; i < A.size(); ++i) {
            num_idxs.emplace_back(A[i], i);
        }
        countAndMergeSort(&num_idxs, 0, num_idxs.size() - 1, &count);
        return count;
    }

private:
    void countAndMergeSort(vector<pair<int, int>> *num_idxs, int start, int end, long long *count) {
        if (end - start <= 0) {
            return;
        }
        int mid = start + (end - start) / 2;
        countAndMergeSort(num_idxs, start, mid, count);
        countAndMergeSort(num_idxs, mid + 1, end, count);

        int l = start;
        vector<pair<int, int>> tmp;
        for (int i = mid + 1; i <= end; ++i) {
            // Merge the two sorted arrays into tmp.
            while (l <= mid && (*num_idxs)[l].first <= (*num_idxs)[i].first) {
                tmp.emplace_back((*num_idxs)[l++]);
            }
            tmp.emplace_back((*num_idxs)[i]);
            *count += mid - l + 1;
        }
        while (l <= mid) {
            tmp.emplace_back((*num_idxs)[l++]);
        }
        // Copy tmp back to num_idxs.
        copy(tmp.begin(), tmp.end(), num_idxs->begin() + start);
    }
};