/*
    Given a binary tree, return the inorder traversal of its nodes' values.
    
    Link: http://www.lintcode.com/en/problem/binary-tree-inorder-traversal/

    Example: 
    	Given binary tree {1,#,2,3},
		   1
		    \
		     2
		    /
		   3
		return [1,3,2].

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/binary-tree-inorder-traversal.cpp
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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        while (curr) {
            if (!curr->left) {
                res.emplace_back(curr->val);
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    res.emplace_back(curr->val);
                    prev = curr;
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};