/*
    Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes. 
    The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

    Link: http://www.lintcode.com/en/problem/lowest-common-ancestor/

    Example: For the following binary tree:

		  4
		 / \
		3   7
		   / \
		  5   6
		LCA(3, 5) = 4

		LCA(5, 6) = 7

		LCA(6, 7) = 7

    Solution: The main point is that we should find these two nodes in the tree, and make sure they exists 
    in the tree. Moreover, if a node which left and right nodes are our target nodes, then we can say this 
    node is our target nodes.

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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if (root == nullptr) {
            return root;
        }
        if (root == A || root == B) {
            return root;
        } else {
            TreeNode* l = lowestCommonAncestor(root->left, A, B);
            TreeNode* r = lowestCommonAncestor(root->right, A, B);
            if (l != nullptr && r != nullptr) {
                return root;
            } else if (l != nullptr) {
                return l;
            } else {
                return r;
            }
        }
        
    }
};