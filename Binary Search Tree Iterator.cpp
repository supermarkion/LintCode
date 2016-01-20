/*
    Design an iterator over a binary search tree with the following rules:
		Elements are visited in ascending order (i.e. an in-order traversal)
		next() and hasNext() queries run in O(1) time in average.

    Link: http://www.lintcode.com/en/problem/binary-search-tree-iterator/

    Example: For the following binary search tree, in-order traversal by using iterator is [1, 6, 10, 11, 12]

		   10
		 /    \
		1      11
		 \       \
		  6       12

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/binary-search-tree-iterator.cpp
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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        curr = root;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !s.empty() || curr != nullptr;
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        // Go to left most descendant.
        while (curr != nullptr) {
            s.emplace(curr);
            curr = curr->left;
        }
        curr = s.top(); // Left most node.
        s.pop();

        TreeNode *node = curr;
        curr = curr->right; // Visit right child.

        return node;
    }
    
private:
    stack<TreeNode *> s;
    TreeNode *curr;
    
};