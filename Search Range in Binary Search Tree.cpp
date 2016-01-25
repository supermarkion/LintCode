/*
    Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. Find all the keys of tree 
    in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. Return all the keys in 
    ascending order.
    
    Link: http://www.lintcode.com/en/problem/search-range-in-binary-search-tree/

    Example: If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].
		    20
		   /  \
		  8   22
		 / \
		4   12

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/search-range-in-binary-search-tree.cpp
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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> result;
        pair<int, int> interval{k1, k2};
        RangeLookupInBSTHelper(root, interval, &result);
        return result;
    }

    void RangeLookupInBSTHelper(const TreeNode* tree,
                                const pair<int, int>& interval,
                                vector<int>* result) {
        if (tree == nullptr) {
            return;
        }
        if (interval.first <= tree->val && tree->val <= interval.second) {
            // tree->data lies in the interval.
            RangeLookupInBSTHelper(tree->left, interval, result);
            result->emplace_back(tree->val);
            RangeLookupInBSTHelper(tree->right, interval, result);
        } else if (interval.first > tree->val) {
            RangeLookupInBSTHelper(tree->right, interval, result);
        } else {  // interval.second > tree->val
            RangeLookupInBSTHelper(tree->left, interval, result);
        }
    }
};