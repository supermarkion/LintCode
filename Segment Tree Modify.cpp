/*
    For a Maximum Segment Tree, which each node has an extra value max to store the maximum value in this node's interval.
	Implement a modify function with three parameter root, index and value to change the node's value with 
	[start, end] = [index, index] to the new given value. Make sure after this change, every node in segment 
	tree still has the max attribute with the correct value.

    Link: http://www.lintcode.com/en/problem/segment-tree-modify/

    Example: For segment tree:
	                      [1, 4, max=3]
	                    /                \
	        [1, 2, max=2]                [3, 4, max=3]
	       /              \             /             \
	[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=3]
	if call modify(root, 2, 4), we can get:

	                      [1, 4, max=4]
	                    /                \
	        [1, 2, max=4]                [3, 4, max=3]
	       /              \             /             \
	[1, 1, max=2], [2, 2, max=4], [3, 3, max=0], [4, 4, max=3]
	or call modify(root, 4, 0), we can get:

	                      [1, 4, max=2]
	                    /                \
	        [1, 2, max=2]                [3, 4, max=0]
	       /              \             /             \
	[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=0]

    Solution: Find and change values, but remember to change max value of node.
    Source: http://www.lintcode.com/en/problem/segment-tree-modify/
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // Out of range.
        if (root == nullptr || root->start > index || root->end < index) {
            return;
        }

        // Change the node's value with [index, index] to the new given value.
        if (root->start == index && root->end == index) {
            root->max = value;
            return;
        }

        modify(root->left, index, value);
        modify(root->right, index, value);

        int left_max = root->left != nullptr ? root->left->max : INT_MIN;
        int right_max = root->right != nullptr ? root->right->max : INT_MIN;

        // Update max.
        root->max = max(left_max, right_max);
    }
};