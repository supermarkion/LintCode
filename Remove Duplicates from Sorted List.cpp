/*
    Given a sorted linked list, delete all duplicates such that each element appear only once.

    Link: http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-list/

    Example: Given 1->1->2, return 1->2. Given 1->1->2->3->3, return 1->2->3.

    Solution: If same, assign to next node.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/remove-duplicates-from-sorted-list.cpp
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        auto iter = head;
        while (iter) {
            auto runner = iter->next;
            while (runner && runner->val == iter->val) {
                runner = runner->next; // if same again, keep going
            }
            iter->next = runner;
            iter = runner;
        }
        return head;
    }
};