/*
    Reverse a linked list.
    
    Link: http://www.lintcode.com/en/problem/reverse-linked-list/

    Example: For linked list 1->2->3, the reversed linked list is 3->2->1.

    Solution: None
    
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/reverse-linked-list.cpp
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode *dummy_head = new ListNode(INT_MIN);

        while (head != nullptr) {
            ListNode *tmp = head->next;
            head->next = dummy_head->next;
            dummy_head->next = head;
            head = tmp;
        }

        return dummy_head->next;
    }
};
