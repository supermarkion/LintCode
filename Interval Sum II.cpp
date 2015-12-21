/*
    Given an integer array in the construct method, implement two methods query(start, end) and modify(index, value):
		For query(start, end), return the sum from index start to index end in the given array.
		For modify(index, value), modify the number in the given index to value

    Link: http://www.lintcode.com/en/problem/interval-sum-ii/

    Example: Given array A = [1,2,7,8,5].
		query(0, 2), return 10.
		modify(0, 4), change A[0] from 1 to 4.
		query(0, 1), return 6.
		modify(2, 1), change A[2] from 7 to 1.
		query(2, 4), return 14.

    Solution: Rewrite a class to implement Segement Tree data structure, which include build, modify
    and query.

    Source: https://github.com/kamyu104/LintCode/blob/master/C++/interval-sum-ii.cpp
*/

// Segment Tree solution.
class SegmentTreeSumNode {
public:
    int start, end;
    long long sum;
    SegmentTreeSumNode *left, *right;
    SegmentTreeSumNode(int start, int end, long long sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /* you may need to use some attributes here */
    SegmentTreeSumNode *root_;

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        root_ = build(A, 0, A.size() - 1);
    }

    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        queryTree(root_, start, end);
    }

    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        modifyTree(root_, index, value);
    }

    // Query Sum in given range.
    long long queryTree(SegmentTreeSumNode *root, int start, int end) {
        // Out of range.
        if (root == nullptr || root->start > end || root->end <  start) {
            return 0;
        }

        // Current segment is totally within range [start, end]
        if (root->start >= start && root->end <= end) {
            return root->sum;
        }

        long long left = queryTree(root->left, start, end);
        long long right = queryTree(root->right, start, end);

        // Find sum in the children.
        return left + right;
    }


    void modifyTree(SegmentTreeSumNode *root, int index, int value) {
        // Out of range.
        if (root == nullptr || root->start > index || root->end < index) {
            return;
        }

        // Change the node's value with [index, index] to the new given value.
        if (root->start == index && root->end == index) {
            root->sum = value;
            return;
        }

        modifyTree(root->left, index, value);
        modifyTree(root->right, index, value);

        int left_sum = root->left != nullptr? root->left->sum : 0;
        int right_sum = root->right != nullptr? root->right->sum : 0;

        // Update sum.
        root->sum = left_sum + right_sum;
    }

    // Build segment tree.
    SegmentTreeSumNode *build(vector<int> &A, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        // The root's start and end is given by build method.
        SegmentTreeSumNode *root = new SegmentTreeSumNode(start, end, 0);

        // If start equals to end, there will be no children for this node.
        if (start == end) {
            root->sum = A[start];
            return root;
        }

        // Left child: start=A.left, end=(A.left + A.right) / 2.
        root->left = build(A, start, (start + end) / 2);

        // Right child: start=(A.left + A.right) / 2 + 1, end=A.right.
        root->right = build(A, (start + end) / 2 + 1, end);

        long long left_sum = root->left != nullptr ? root->left->sum : 0;
        long long right_sum = root->right != nullptr ? root->right->sum : 0;

        // Update sum.
        root->sum = left_sum + right_sum;
        return root;
    }
};

