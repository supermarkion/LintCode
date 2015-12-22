/*
    The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.
    start and end are both integers, they should be assigned in following rules:
      The root's start and end is given by build method.
      The left child of node A has start=A.left, end=(A.left + A.right) / 2.
      The right child of node A has start=(A.left + A.right) / 2 + 1, end=A.right.
      if start equals to end, there will be no children for this node.
    Implement a build method with two parameters start and end, so that we can create a corresponding segment tree with every node 
    has the correct start and end value, return the root of this segment tree.
    
    Link: http://www.lintcode.com/en/problem/segment-tree-build/

    Example:  Given start=0, end=3. The segment tree will be:

                   [0,  3]
                 /        \
          [0,  1]           [2, 3]
          /     \           /     \
       [0, 0]  [1, 1]     [2, 2]  [3, 3]
    Given start=1, end=6. The segment tree will be:

                   [1,  6]
                 /        \
          [1,  3]           [4,  6]
          /     \           /     \
       [1, 2]  [3,3]     [4, 5]   [6,6]
       /    \           /     \
    [1,1]   [2,2]     [4,4]   [5,5]

    Solution: Follow definition, and use recursion method to solve.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/segment-tree-build.cpp
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        if (start > end) {
            return nullptr;
        }

        // The root's start and end is given by build method.
        SegmentTreeNode *root = new SegmentTreeNode(start, end);

        // If start equals to end, there will be no children for this node.
        if (start == end) {
            return root;
        }

        // Left child: start=A.left, end=(A.left + A.right) / 2.
        root->left = build(start, (start + end) / 2);

        // Right child: start=(A.left + A.right) / 2 + 1, end=A.right.
        root->right = build((start + end) / 2 + 1, end);

        return root;
    }
};