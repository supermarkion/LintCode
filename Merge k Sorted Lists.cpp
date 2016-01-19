/*
    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

    Link: http://www.lintcode.com/en/problem/merge-k-sorted-lists/

    Example: Given lists:
		[
		  2->4->null,
		  null,
		  -1->null
		],
		return -1->2->4->null.

    Solution: Based on this problem, if we want to speed up merge several times, we have to apply divide and merge.
    Then, for the divide method, we divide a the lists into left part and right, and then perform merge them.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/merge-k-sorted-lists.cpp
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode dummy(INT_MIN);
        ListNode *cur = &dummy;

        // Use min heap to keep the smallest node of each list
        priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;
        // std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;
        for (const auto& n : lists) {
            if (n != nullptr) {
                min_heap.emplace(n);
            }
        }

        while (!min_heap.empty()) {
            // Get min of k lists.
            ListNode *node = min_heap.top();
            min_heap.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next != nullptr) {
                min_heap.emplace(node->next);
            }
        }

        return dummy.next;
    }

    struct Compare {
        bool operator() (const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };
};