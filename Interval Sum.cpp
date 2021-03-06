/*
    Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list. 
    Each query has two integers [start, end]. For each query, calculate the sum number between index start 
    and end in the given array, return the result list.

    Link: http://www.lintcode.com/en/problem/interval-sum/

    Example: For array [1,2,7,8,5], and queries [(0,4),(1,2),(2,4)], return [23,9,20]

    Solution: Use the same approach as Part 2

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/interval-sum.cpp
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
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
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        vector<long long> res;

        // Build segment tree.
        SegmentTreeSumNode *root = build(A, 0, A.size() - 1);

        // Do each query.
        for (const auto& q : queries) {
            res.emplace_back(query(root, q.start, q.end));
        }

        return res;
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

        long long left_sum = root->left != nullptr? root->left->sum : 0;
        long long right_sum = root->right != nullptr? root->right->sum : 0;

        // Update sum.
        root->sum = left_sum + right_sum;
        return root;
    }


    // Query sum in given range.
    long long query(SegmentTreeSumNode *root, int start, int end) {
        // Out of range.
        if (root == nullptr || root->start > end || root->end <  start) {
            return 0;
        }

        // Current segment is totally within range [start, end]
        if (root->start >= start && root->end <= end) {
            return root->sum;
        }

        long long left = query(root->left, start, end);
        long long right = query(root->right, start, end);

        // Find sum in the children.
        return left + right;
    }
};