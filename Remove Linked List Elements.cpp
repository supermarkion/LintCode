/*
	Remove all elements from a linked list of integers that have value val.
	Link: http://www.lintcode.com/en/problem/palindrome-partitioning/
	Example: Given 1->2->3->3->4->5->3, val = 3, you should return the list as 1->2->4->5
	Solution: skip the node which equals to given val.
	Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/remove-linked-list-elements.cpp
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
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        // numeric_limits: Provides information about the properties of arithmetic typ
        // (either integral or floating-point) in the specific platform for which the 
        // library compiles.
        ListNode dummy = ListNode(numeric_limits<int>::min());
        dummy.next = head;
        ListNode *prev = &dummy, *cur = dummy.next;
        
        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next;
                // delete cur;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};