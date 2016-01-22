/*
    Given a binary tree, return the postorder traversal of its nodes' values.
    
    Link: http://www.lintcode.com/en/problem/binary-tree-postorder-traversal/

    Example: 
    	Given binary tree {1,#,2,3},
		   1
		    \
		     2
		    /
		   3
		return [3,2,1].

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/binary-tree-postorder-traversal.cpp
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        TreeNode dummy(INT_MIN);
        dummy.left = root;
        TreeNode *curr = &dummy;
        while (curr) {
            if (!curr->left) {
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
                    vector<int> v = trace_back(curr->left, node);
                    res.insert(res.end(), v.begin(), v.end());
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return res;
    }

    vector<int> trace_back(TreeNode *frm, TreeNode *to) {
        vector<int> res;
        TreeNode *curr = frm;
        while (curr != to) {
            res.emplace_back(curr->val);
            curr = curr->right;
        }
        res.emplace_back(to->val);
        reverse(res.begin(), res.end());
        return res;
    }
};