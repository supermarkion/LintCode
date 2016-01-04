/*
    You have two numbers represented by a linked list, where each node contains a single digit. 
    The digits are stored in reverse order, such that the 1's digit is at the head of the list. 
    Write a function that adds the two numbers and returns the sum as a linked list.

    Link: http://www.lintcode.com/en/problem/add-two-numbers/

    Example: 
    	Given 7->1->6 + 5->9->2. That is, 617 + 295.
		Return 2->1->9. That is 912.
		Given 3->1->5 and 5->9->2, return 8->0->8.

    Solution: None

    Source: Vhttp://www.1point3acres.com/bbs/thread-138272-10-1.html
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
                
        ListNode *h;
        ListNode *t;
        int c;
                
        h = t = new ListNode(l1->val + l2->val);
        c = t->val / 10;
        t->val %= 10;
        l1 = l1->next;
        l2 = l2->next;
                
        while (l1 != NULL && l2 != NULL) {
            t->next = new ListNode(l1->val + l2->val + c);
            t = t->next;
            c = t->val / 10;
            t->val %= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            t->next = new ListNode(l1->val + c);
            t = t->next;
            c = t->val / 10;
            t->val %= 10;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            t->next = new ListNode(l2->val + c);
            t = t->next;
            c = t->val / 10;
            t->val %= 10;
            l2 = l2->next;
        }
        if (c) {
            t->next = new ListNode(1);
        }
        return h;
    }
};