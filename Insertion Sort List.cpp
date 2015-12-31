/*
    Sort a linked list using insertion sort.

    Link: http://www.lintcode.com/en/problem/insertion-sort-list/

    Example: Given 1->3->2->0->null, return 0->1->2->3->null.
    
    Solution: Perform Insert Sort Algorithm

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/insertion-sort-list.cpp
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode dummy(INT_MIN);

        ListNode *cur = head;
        ListNode *prev = nullptr;
        ListNode *pos = nullptr;

        while (cur) {
            pos = findInsertPos(&dummy, cur->val); // find insert pos
            ListNode *tmp = cur->next; 			   // exchange locations
            cur->next = pos->next;
            pos->next = cur;
            cur = tmp;
        }

        return dummy.next;
    }

    ListNode* findInsertPos(ListNode *head, int x) {
        ListNode *pre = nullptr;
        for (ListNode *cur = head; cur && cur->val <= x;
             pre = cur, cur = cur->next);
        return pre;
    }
};
