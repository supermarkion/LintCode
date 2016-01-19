/*
    Given a binary tree, find its maximum depth. The maximum depth is the number of nodes along the longest path 
    from the root node down to the farthest leaf node.

    Link: http://www.lintcode.com/en/problem/maximum-depth-of-binary-tree/

    Example: Given a binary tree as follow:
		  1
		 / \ 
		2   3
		   / \
		  4   5
		The maximum depth is 3.

    Solution: It is typical recursion method problem, and we just want to know which branch can get deeper, 
    and it is easy to write method.

    Source: None
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
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};