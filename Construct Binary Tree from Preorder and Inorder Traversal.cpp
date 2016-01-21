/*
    Given preorder and inorder traversal of a tree, construct the binary tree.

    Link: http://www.lintcode.com/en/problem/construct-binary-tree-from-preorder-and-inorder-traversal/

    Example: Given in-order [1,2,3] and pre-order [2,1,3], return a tree:

		  2
		 / \
		1   3

    Solution: From the pre-order array, we know that first element is the root. We can find the root in in-order array.
	Then we can identify the left and right sub-trees of the root from in-order array. Using the length of left
	sub-tree, we can identify left and right sub-trees in pre-order array. Recursively, we can build up the tree.
	It based on a definition that in the in-order traversal, the left node is located its left, and right node located
	its right.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/construct-binary-tree-from-preorder-and-inorder-traversal.cpp
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        unordered_map<int, size_t> in_entry_idx_map;
        for (size_t i = 0; i < inorder.size(); ++i) {
            in_entry_idx_map.emplace(inorder[i], i);
        }
        return ReconstructPreInOrdersHelper(preorder, 0, preorder.size(), inorder, 0, 
        										inorder.size(), in_entry_idx_map);
    }

    // Reconstructs the binary tree from pre[pre_s : pre_e - 1] and
    // in[in_s : in_e - 1].
    TreeNode *ReconstructPreInOrdersHelper(const vector<int>& pre, size_t pre_s, size_t pre_e,
                                           const vector<int>& in, size_t in_s, size_t in_e,
                                           const unordered_map<int, size_t>& in_entry_idx_map) {
        if (pre_e > pre_s && in_e > in_s) {
            auto idx = in_entry_idx_map.at(pre[pre_s]);
            auto left_tree_size = idx - in_s;

            TreeNode *node = new TreeNode(pre[pre_s]);
            // Recursively builds the left subtree.
            node->left = ReconstructPreInOrdersHelper(pre, pre_s + 1, pre_s + 1 + left_tree_size,
                                                      in, in_s, idx, in_entry_idx_map);
            // Recursively builds the right subtree.
            node->right = ReconstructPreInOrdersHelper(pre, pre_s + 1 + left_tree_size, pre_e,
                                                       in, idx + 1, in_e, in_entry_idx_map);
            return node;
        }
        return nullptr;
    }
};