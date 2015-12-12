/*
    Check if two binary trees are identical. Identical means the two binary trees have the same
    structure and every identical position has the same value.

    Link: http://www.lintcode.com/en/problem/identical-binary-tree/
    Example: 
            1            1
           / \          / \
          2   2  and   2   2 
         /            /
        4            4

    are identical.

    Solution: traversal the two trees, and compare one node by one node.
    Source: http://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
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
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        if (a == NULL && b == NULL) {
            return true;
        }
        if (a != NULL && b != NULL) {
            return (a->val == b->val &&
                    isIdentical(a->left, b->left) &&
                    isIdentical(a->right, b->right));
        }
        return false;
    }
};