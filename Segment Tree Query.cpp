/*
    For an integer array (index from 0 to n-1, where n is the size of this array), 
    in the corresponding SegmentTree, each node stores an extra attribute max to denote 
    the maximum number in the interval of the array (index from start to end).
    Design a query method with three parameters root, start and end, find the maximum 
    nmber in the interval [start, end] by the given root of segment tree.
    
    Link: http://www.lintcode.com/en/problem/segment-tree-query/

    Example:  For array [1, 4, 2, 3], the corresponding Segment Tree is:

                  [0, 3, max=4]
                 /             \
          [0,1,max=4]        [2,3,max=3]
          /         \        /         \
    [0,0,max=1] [1,1,max=4] [2,2,max=2], [3,3,max=3]
    
    query(root, 1, 1), return 4
    query(root, 1, 2), return 4
    query(root, 2, 3), return 3
    query(root, 0, 2), return 4

    Solution: Use range to find max value.

    Source: http://www.lintcode.com/en/problem/segment-tree-query/
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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // Out of range.
        if (root == nullptr || root->start > end || root->end <  start) {
            return INT_MIN;
        }

        // Current segment is totally within range [start, end]
        if (root->start >= start && root->end <= end) {
            return root->max;
        }

        int left = query(root->left, start, end);
        int right = query(root->right, start, end);

        // Find max in the children.
        return max(left, right);
    }
};