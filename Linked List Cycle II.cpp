/*
    Given a linked list, return the node where the cycle begins. if there is no cycle, return null.

    Link: http://www.lintcode.com/en/problem/linked-list-cycle-ii/

    Example: Given -21->10->4->5, tail connects to node index 1，return 10

    Solution: The main part is that we should make sure that it exists a cycle in the linked list. Then, if we can find next
    node, we make quick pointer move twice, or return null to get there is no cycle in the linked list.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/linked-list-cycle-ii.cpp
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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast) {  // There is a cycle.
                slow = head;
                // Both pointers advance at the same time.
                while (slow != fast) {
                    slow = slow->next, fast = fast->next;
                }
                return slow;  // slow is the begin of cycle.
            }
        }
        return nullptr;  // No cycle.
    }
};