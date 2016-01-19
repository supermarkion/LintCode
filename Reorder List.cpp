/*
    Given a singly linked list L: L0→L1→…→Ln-1→Ln, reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→… 
    You must do this in-place without altering the nodes' values.

    Link: http://www.lintcode.com/en/problem/reorder-list/

    Example: Given 1->2->3->4->null, reorder it to 1->4->2->3->null.

    Solution: In this problem, there are three templates on linked list.

    Source: http://www.lintcode.com/en/problem/reorder-list/
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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (!head) {
            return;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // split into two lists
        ListNode *tmp = slow->next;
        slow->next = nullptr;
        slow = tmp;

        merge(head, reverse(slow));
    }

private:
    ListNode *reverse(ListNode *head) {
        ListNode dummy(INT_MIN);

        while (head) {
            ListNode *tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }

        return dummy.next;
    }

    ListNode *merge(ListNode *list1, ListNode *list2) {
        ListNode dummy(INT_MIN);
        ListNode *ptr = &dummy;

        while (list1 && list2) {
            ListNode *tmp = list1->next; // backup list1 next

            ptr->next = list1;
            ptr = ptr->next;
            ptr->next = list2; // list1 next is overwritten
            ptr = ptr->next;

            list1 = tmp;
            list2 = list2->next;
        }

        if (list1) {
            ptr->next = list1; // append remaining list1
        }

        return dummy.next;
    }
};