/*
    Given a linked list, determine if it has a cycle in it.

    Link: http://www.lintcode.com/en/problem/linked-list-cycle/

    Example: Given -21->10->4->5, tail connects to node index 1, return true

    Solution: Applying two pointers to solve this problme.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/linked-list-cycle.cpp
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast) {  // There is a cycle.
                return true;
            }
        }
        return false;  // No cycle.
    }
};


