/*
    Merge two sorted (ascending) linked lists and return it as a new sorted list. The new sorted list
    should be made by splicing together the nodes of the two lists and sorted in ascending order.

    Link: http://www.lintcode.com/en/problem/merge-two-sorted-lists/

    Example: Given 1->3->8->11->15->null, 2->null , return 1->2->3->8->11->15->null.

    Solution: Compare two head nodes, until one meet end.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/merge-two-sorted-lists.cpp
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        // Creates a dummy head.
        ListNode * dummy_head = new ListNode(INT_MIN);
        auto tail = dummy_head;

        while (l1 && l2) {
            AppendNode(l1->val < l2->val ? &l1 : &l2, &tail);
        }

        if (l1) {
            // Appends the remaining nodes of l1.
            AppendNode(&l1, &tail);
        } else if (l2) {
            // Appends the remaining nodes of l2.
            AppendNode(&l2, &tail);
        }
        return dummy_head->next;
    }

    void AppendNode(ListNode ** node,
                    ListNode ** tail) {
        (*tail)->next = *node;
        *tail = *node;  // Resets tail to the last node.
        *node = (*node)->next;
    }
};