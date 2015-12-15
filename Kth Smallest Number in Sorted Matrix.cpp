/*
    Find the kth smallest number in at row and column sorted matrix.
    Link: http://www.lintcode.com/en/problem/kth-smallest-number-in-sorted-matrix/
    Example: Given k = 4 and a matrix:
    [
	  [1 ,5 ,7],
	  [3 ,7 ,8],
	  [4 ,8 ,9],
	]
	return 5
    Solution: apply a PriorityQueue to sort and return value, or perform BST to solve. 
    Source: 
    	http://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/
    	https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/kth-smallest-number-in-sorted-matrix.cpp
*/

class Solution {
public:

    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
                if (matrix.size() < matrix[0].size()) {  // Height is smaller.
            return horizontal_search(matrix, k);
        } else {  // Width is smaller.
            return vertical_search(matrix, k);
        }
    }

    int horizontal_search(const vector<vector<int>> &matrix, int k) {
        multimap<int, pair<int, int>> min_bst;

        // Init BST by the first element of the first kth row.
        for (int i = 0; i < min(static_cast<int>(matrix.size()), k); ++i) {
            min_bst.emplace(pair<int, pair<int, int>>{matrix[i][0], {i, 0}});
        }

        int kth_smallest = INT_MAX;
        while (!min_bst.empty() && k--) {
            // Pop the min of BST.
            if (k == 0) {
                kth_smallest = min_bst.cbegin()->first;
            }
            // Pop the min of BST.
            int i = min_bst.cbegin()->second.first;
            int j = min_bst.cbegin()->second.second;
            min_bst.erase(min_bst.cbegin());

            // Insert the next possible element.
            if (j + 1 < matrix[i].size()) {
                min_bst.emplace(pair<int, pair<int, int>>{matrix[i][j + 1], {i, j + 1}});
            }
        }

        return kth_smallest;
    }

    int vertical_search(const vector<vector<int>> &matrix, int k) {
        multimap<int, pair<int, int>> min_bst;

        // Init BST by the first element of the first kth column.
        for (int j = 0; j < min(static_cast<int>(matrix[0].size()), k); ++j) {
            min_bst.emplace(pair<int, pair<int, int>>{matrix[0][j], {0, j}});
        }

        int kth_smallest = INT_MAX;
        while (!min_bst.empty() && k--) {
            // Pop the min of Heap.
            if (k == 0) {
                kth_smallest = min_bst.cbegin()->first;
            }
            // Pop the min of BST.
            int i = min_bst.cbegin()->second.first;
            int j = min_bst.cbegin()->second.second;
            min_bst.erase(min_bst.cbegin());

            // Insert the next possible element.
            if (i + 1 < matrix.size()) {
                min_bst.emplace(pair<int, pair<int, int>>{matrix[i + 1][j], {i + 1, j}});
            }
        }

        return kth_smallest;
    }
};