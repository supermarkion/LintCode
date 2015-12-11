/*
	Given a linked list, swap every two adjacent nodes and return its head.
	Link: http://www.lintcode.com/en/problem/swap-nodes-in-pairs/
	Example: Given 1->2->3->4, you should return the list as 2->1->4->3.
	Solution: save all next nodes, and swap them easiler.
	Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/swap-nodes-in-pairs.cpp
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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        ListNode dummy = ListNode(numeric_limits<int>::min());
        dummy.next = head;
        ListNode *cur = &dummy;
        
        while (cur->next && cur->next->next) {
            ListNode *next_one = cur->next;
            ListNode *next_two = next_one->next;
            ListNode *next_three = next_two->next;
            cur->next = next_two;
            next_two->next = next_one;
            next_one->next = next_three;
            cur = next_one;
        }
        return dummy.next;
    }
};