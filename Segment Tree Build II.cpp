/*
    The structure of Segment Tree is a binary tree which each node has two attributes start
    and end denote an segment / interval.
    
    start and end are both integers, they should be assigned in following rules:
    - The root's start and end is given by build method.
    - The left child of node A has start=A.left, end=(A.left + A.right) / 2.
    - The right child of node A has start=(A.left + A.right) / 2 + 1, end=A.right.
    - if start equals to end, there will be no children for this node.

    Implement a build method with a given array, so that we can create a corresponding segment
    tree with every node value represent the corresponding interval max value in the array,
    return the root of this segment tree.

    Link: http://www.lintcode.com/en/problem/segment-tree-build-ii/
    Example: 
    Solution: Simple data structure, which max attribute is difficult one, and we should update it
    based on children nodes max variables.
    Source: https://github.com/kamyu104/LintCode/blob/master/C++/segment-tree-build-ii.cpp
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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        return buildRecu(A, 0, A.size() - 1);
    }
    
    SegmentTreeNode * buildRecu(const vector<int>& A,
                                const int start, const int end) {
        if (start > end) {
            return nullptr;
        }
        SegmentTreeNode *root = new SegmentTreeNode(start, end, INT_MAX);
        
        if (start == end) {
            root->max = A[start];
            return root;
        }
        
        root->left = buildRecu(A, start, (start + end) / 2);
        root->right = buildRecu(A, (start + end) / 2 + 1, end);
        
        const int left_max = root->left != nullptr ? root->left->max : INT_MAX;
        const int right_max = root->right != nullptr ? root->right->max : INT_MAX;
        
        root->max = max(left_max, right_max);
        return root;
    }
};