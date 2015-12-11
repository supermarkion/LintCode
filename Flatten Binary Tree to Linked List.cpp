/*
	Flatten a binary tree to a fake "linked list" in pre-order traversal. 
	Here we use the right pointer in TreeNode as the next pointer in ListNode.
	Link: http://www.lintcode.com/en/problem/flatten-binary-tree-to-linked-list/
	Example: 

		 1                1
		/ \				   \
       2   5      =>        2
      / \   \                \
	 3   4   6                3
	 						   \
								4
								 \...

	Solution: use recursion to get flatten list order (root, left, right)
	Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/flatten-binary-tree-to-linked-list.cpp
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        // write your code here
        TreeNode *list_head = nullptr;
        flatterHelper(root, &list_head);
    }
    
    TreeNode *flatterHelper(TreeNode *root, TreeNode **list_head) {
        if (root) {
            flatterHelper(root->right, list_head);
            flatterHelper(root->left, list_head);
            root->right = *list_head;
            root->left = nullptr;
            *list_head = root;
        }
    }
};