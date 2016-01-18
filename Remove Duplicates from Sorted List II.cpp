/*
    Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

    Link: http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-list-ii/

    Example: Given 1->2->3->3->4->4->5, return 1->2->5. Given 1->1->1->2->3, return 2->3.

    Solution: Set a dummpy node, and if same, assign to next node from pre-head.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/remove-duplicates-from-sorted-list-ii.cpp
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode *dummy_head = new ListNode(INT_MIN);
        ListNode *pre = dummy_head;
        while (head) {
            if (head->next && head->next->val == head->val) {
                auto val = head->val;
                while (head && head->val == val) {
                    head = head->next;
                }
                pre->next = head; // if this head is dupilcate, also delete
            } else {
                pre->next = head;
                pre = head;
                head = head->next; // only link to 'clear' head node
            }
        }
        return dummy_head->next;
    }
};