/*
    Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along 
    the shortest path from the root node down to the nearest leaf node.

    Link: http://www.lintcode.com/en/problem/minimum-depth-of-binary-tree/

    Example: 
    	Given a binary tree as follow:
		  1
		 / \ 
		2   3
		   / \
		  4   5
		The minimum depth is 2.

    Solution: go throught each nodes in tree, and find min depth of two child-brunch.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/minimum-depth-of-binary-tree.cpp
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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if (root == nullptr) {
            return 0;
        }

        // Both children exist.
        if (root->left != nullptr && root->right != nullptr) {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
        else {
            return 1 + max(minDepth(root->left), minDepth(root->right));
        }
    }
};