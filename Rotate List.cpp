/*
    iven a list, rotate the list to the right by k places, where k is non-negative.

    Link: http://www.lintcode.com/en/problem/rotate-list/

    Example: Given 1->2->3->4->5 and k = 2, return 4->5->1->2->3.

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/rotate-list.cpp
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        ListNode *dummy_head = new ListNode(INT_MIN);
        dummy_head->next = head;

        // Get length of the list.
        ListNode *cur = dummy_head;
        int len = 0;
        while (cur->next) {
            ++len;
            cur = cur->next;
        }
        if (len == 0) {
            return nullptr;
        }
        k %= len;
        if (k == 0) {
            return head;
        }

        // Find the position to split.
        ListNode *slow = dummy_head;
        ListNode *fast = dummy_head;
        while (k) {
            fast = fast->next;
            --k;
        }
        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        dummy_head->next = slow->next; // New head.
        slow->next = nullptr; // Split
        fast->next = head; // Link.

        return dummy_head->next;
    }
    
};