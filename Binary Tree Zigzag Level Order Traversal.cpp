/*
    Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, 
    then right to left for the next level and alternate between).

    Link: http://www.lintcode.com/en/problem/binary-tree-zigzag-level-order-traversal/

    Example: Given binary tree {3,9,20,#,#,15,7},

            3
           / \
          9  20
            /  \
           15   7

    return its zigzag level order traversal as:

        [
          [3],
          [20,9],
          [15,7]
        ]

    Solution: Perfrom traversal as usual, but use a flag to make decision on whether perform converse operation.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/binary-tree-zigzag-level-order-traversal.cpp
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        bool isLeftToRight = true;
        vector<vector<int>> output;
        queue<TreeNode *> q;
        vector<int> cur_level;

        if (root == nullptr) {
            return output;
        }

        q.emplace(root);
        int cur_level_size = 1;
        while (!q.empty()) {
            // Get the front node in current level.
            TreeNode *n = q.front();
            q.pop();
            --cur_level_size;

            // Append to the current level.
            cur_level.emplace_back(n->val);

            if (n->left) {
                q.emplace(n->left);
            }
            if (n->right) {
                q.emplace(n->right);
            }

            // Current level comes to the end.
            // Goes to the next level.
            if (cur_level_size == 0) {
                if (!isLeftToRight) {
                    reverse(cur_level.begin(), cur_level.end());
                }
                isLeftToRight = !isLeftToRight;
                cur_level_size = q.size();
                output.emplace_back(move(cur_level));
            }
        }
        return output;
    }
};