/*
	Given a binary tree, return all root-to-leaf paths.
	Link: http://www.lintcode.com/en/problem/binary-tree-paths/
	Example: 
	Solution: update the path, and use path to construct string when we need to simple the
	process on reduce path list.
	Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/binary-tree-paths.cpp
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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<TreeNode *> path;
        binaryTreePathsRecu(root, &path, &result);
        return result;
    }

    void binaryTreePathsRecu(TreeNode *node, vector<TreeNode *> *path,
                             vector<string> *result) {
        if (!node) {
            return;
        }

        if (!node->left && !node->right) {
            string ans = "";
            for (const auto& n : *path) {
                ans.append(to_string(n->val).append("->"));
            }
            // move is used to indicate that an object t may be "moved from", 
            // i.e. allowing the efficient transfer of resources from t to another object
            // aims to change the content from left and right
            result->emplace_back(move(ans.append(to_string(node->val))));
        }

        if (node->left) {
            path->emplace_back(node);
            binaryTreePathsRecu(node->left, path, result);
            path->pop_back();
        }

        if (node->right) {
            path->emplace_back(node);
            binaryTreePathsRecu(node->right, path, result);
            path->pop_back();
        }
    }
};