/*
    You have two every large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. 
    Create an algorithm to decide if T2 is a subtree of T1.
    Link: http://www.lintcode.com/en/problem/subtree/
    Example: 
    Solution: Loop main tree to left or right, once new subtree is same with compared tree, we set true.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/subtree.cpp
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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (!T2) {
            return true;
        } else if (!T1) {
            return false;
        } else {
            return isSameTree(T1, T2) ||
                   isSubtree(T1->left, T2) ||
                   isSubtree(T1->right, T2);
        }
    }
    
    bool isSameTree(TreeNode *T1, TreeNode *T2) {
        if (!T1 && !T2) {
            return true;
        }
        if (T1 && T2) {
            return T1->val == T2->val &&
                   isSameTree(T1->left, T2->left) &&
                   isSameTree(T1->right, T2->right);
        }
        return false;
    }
    
};