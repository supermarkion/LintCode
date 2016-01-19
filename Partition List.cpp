/*
    Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    You should preserve the original relative order of the nodes in each of the two partitions.

    Link: http://www.lintcode.com/en/problem/partition-list/

    Example: Given 1->4->3->2->5->2->null and x = 3, return 1->2->2->4->3->5->null.

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/partition-list.cpp
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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode *dummy_smaller = new ListNode(INT_MIN);
        ListNode *dummy_larger = new ListNode(INT_MIN);
        ListNode *smaller = dummy_smaller;
        ListNode *larger = dummy_larger;

        while (head) {
            if (head->val < x) {
                smaller->next = head;
                smaller = smaller->next;
            } else {
                larger->next = head;
                larger = larger->next;
            }
            head = head->next;
        }
        smaller->next = dummy_larger->next;
        larger->next = nullptr;

        return dummy_smaller->next;
    }
};


