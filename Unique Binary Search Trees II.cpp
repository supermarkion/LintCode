/*
    Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

    Link: http://www.lintcode.com/en/problem/unique-binary-search-trees-ii/

    Example:
    	Given n = 3, your program should return all 5 unique BST's shown below.
        1         3     3      2      1
         \       /     /      / \      \
          3     2     1      1   3      2
         /     /       \                 \
        2     1         2                 3

    Solution: Perform standard BST method to construct all kinds of trees. By the way, once we consturct
    one solution, we can add to return results.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/unique-binary-search-trees-ii.cpp
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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> output;
        if (start > end) {
            output.emplace_back(nullptr);
            return output;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode *> leftSubTrees = generateTrees(start, i - 1);
            vector<TreeNode *> rightSubTrees = generateTrees(i + 1, end);
            for (const auto& left : leftSubTrees) {
                for (const auto& right : rightSubTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = clone(left);
                    root->right = clone(right);
                    output.emplace_back(root);
                }
            }

        }
        return output;
    }

    TreeNode *clone(TreeNode *root) {
        TreeNode *newRoot = nullptr;

        if (root) {
            newRoot = new TreeNode(root->val);
            newRoot->left = clone(root->left);
            newRoot->right = clone(root->right);
        }

        return newRoot;
    }
};