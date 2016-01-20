/*
    Given a binary tree, determine if it is height-balanced. For this problem, a height-balanced binary tree 
    is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

    Link: http://www.lintcode.com/en/problem/balanced-binary-tree/

    Example: Given binary tree A={3,9,20,#,#,15,7}, B={3,#,20,15,7}

		A)  3            B)    3 
		   / \                  \
		  9  20                 20
		    /  \                / \
		   15   7              15  7
		The binary tree A is a height-balanced binary tree, but B is not.

    Solution: We set when facing error, we return −1 to upper layer. And when the upper layer get −1, and we will know
    that there is a error.

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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if (root == nullptr) {
            return true;
        }
        return helper(root) != -1;
    }
    
    int helper(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = helper(root->left);
        int rightDepth = helper(root->right);
        if (leftDepth == -1 || rightDepth == -1 ||
                abs(rightDepth - leftDepth) > 1) {
            return -1;
        }
        return 1 + max(rightDepth, leftDepth);
    }
};