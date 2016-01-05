/*
    Find the nth to last element of a singly linked list. 
    The minimum number of nodes in list is n.
    Link: http://www.lintcode.com/en/problem/nth-to-last-node-in-list/
    Example: Given a List  3->2->1->5->null and n = 2, return node  whose value is 1.
    Solution: Two pointers method.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/nth-to-last-node-in-list.cpp
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
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        ListNode *slow = head;
        ListNode *fast = head;

        // fast is n-step ahead.
        while (n > 0) {
            fast = fast->next;
            --n;
        }

        // When fast reaches the end, slow must be nth to last node.
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};


