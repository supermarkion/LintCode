/*
    Given a binary tree, determine if it is a valid binary search tree (BST). Assume a BST is defined as follows:
		The left subtree of a node contains only nodes with keys less than the node's key.
		The right subtree of a node contains only nodes with keys greater than the node's key.
		Both the left and right subtrees must also be binary search trees.

    Link: http://www.lintcode.com/en/problem/validate-binary-search-tree/

    Example: An example:
		  2
		 / \
		1   4
		   / \
		  3   5
		The above binary tree is serialized as {2,1,4,#,#,3,5} (in level order).

    Solution: We use recursion based on definition of binary search tree, which left subtree of contains nodes that less than
    node key, and right subtree only have nodes which greater than node value.

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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        if (root == nullptr) {
            return true;
        }
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode *root, long lower, long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= upper || root->val <= lower) {
            return false;
        }
        bool isleftValidBST = helper(root->left, lower, root->val);
        bool isrightValidBST = helper(root->right, root->val, upper);
        return isleftValidBST && isrightValidBST;
    }
};