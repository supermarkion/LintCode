/*
    Given a linked list and two values v1 and v2. Swap the two nodes in the linked list with values v1 and v2. 
    It's guaranteed there is no duplicate values in the linked list. If v1 or v2 does not exist in the given 
    linked list, do nothing.
    
    Link: http://www.lintcode.com/en/problem/swap-two-nodes-in-linked-list/

    Example: Given 1->2->3->4->null and v1 = 2, v2 = 4.
		Return 1->4->3->2->null.

    Solution: None

    Source: None
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
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        if (v1 == v2) {
            return head;
        }
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        // Search for v1 (keep track of prev1 and Curr1
        ListNode* pre1 = dummy;
        ListNode* curr1 = head;
        while (curr1 && curr1->val != v1)
        {
            pre1 = curr1;
            curr1 = curr1->next;
        }
     
        // Search for v2 (keep track of prev2 and Curr2
        ListNode* pre2 = dummy;
        ListNode* curr2 = head;
        while (curr2 && curr2->val != v2)
        {
            pre2 = curr2;
            curr2 = curr2->next;
        }
     
        if (curr2 && curr1) {
            if (curr1->next != curr2 && curr2->next != curr1) {
                ListNode *next1 = curr1->next;
                ListNode *next2 = curr2->next;
                pre1->next = curr2;
                curr2->next = next1;
                pre2->next = curr1;
                curr1->next = next2;
            } else if (curr1->next == curr2) {
                ListNode *next = curr2->next;
                pre1->next = curr2;
                curr2->next = curr1;
                curr1->next = next;
            } else {
                ListNode *next = curr1->next;
                pre2->next = curr1;
                curr1->next = curr2;
                curr2->next = next;
            }
        }
        
        return dummy->next;
    }
};