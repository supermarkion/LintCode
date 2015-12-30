/*
    Given a linked list, remove the nth node from the end of list and return its head.

    Link: http://www.lintcode.com/en/problem/remove-nth-node-from-end-of-list/

    Example: Given linked list: 1->2->3->4->5->null, and n = 2.
	After removing the second node from the end, the linked list becomes 1->2->3->5->null.
    
    Solution: Two pointers problem.

    Source: http://www.lintcode.com/en/problem/remove-nth-node-from-end-of-list/
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
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        // fast is n-step ahead.
        while (n > 0) {
            fast = fast->next;
            --n;
        }

        // When fast reaches the end, slow must be nth to last node.
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *node_to_delete = slow->next; // use pointer to define this address
        slow->next = slow->next->next;
        delete node_to_delete;

        return dummy->next;
    }
};