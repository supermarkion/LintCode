/*
    Invert a binary tree.
    Link: http://www.lintcode.com/en/problem/invert-binary-tree/
    Example: 
    	1			 1
       / \			/ \
	  2   3  =>    3   2
	 	 /          \
	 	4            4
    Solution: we use a queue to save un-processed node, and swap their left and right nodes.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/invert-binary-tree.cpp
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if (root != nullptr) {
            queue<TreeNode *> nodes;
            nodes.emplace(root);
            while (!nodes.empty()) {
                auto node = nodes.front();
                nodes.pop();
                swap(node->left, node->right);
                if (node->left != nullptr) {
                    nodes.emplace(node->left);
                }
                if (node->right != nullptr) {
                    nodes.emplace(node->right);
                }
            }
        }
    }
};