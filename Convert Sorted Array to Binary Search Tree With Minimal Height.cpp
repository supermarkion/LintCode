/*
    Given a sorted (increasing order) array, Convert it to create a binary tree with minimal height.
    Link: http://www.lintcode.com/en/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height/
    Example: Given [1,2,3,4,5,6,7], return
					 4
				   /   \
                  2     6
				 / \   / \
                1   3 5   7
	Solution: Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/convert-sorted-array-to-binary-search-tree-with-minimal-height.cpp
*/

 /**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        return sortedArrayToBSTHelper(A, 0, A.size());
    }
    
    TreeNode *sortedArrayToBSTHelper(vector<int> &A, int start, int end) {
        if (start < end) {
            TreeNode *node = new TreeNode(A[start + (end - start) / 2]);
            node->left = sortedArrayToBSTHelper(A, start, start + (end - start) / 2);
            node->right = sortedArrayToBSTHelper(A, start + (end - start) / 2 + 1, end);
            return node;
        }
        return nullptr;
    }

};


