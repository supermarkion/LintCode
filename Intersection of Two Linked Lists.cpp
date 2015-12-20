/*
    Write a program to find the node at which the intersection of two singly linked lists begins.
    Link: http://www.lintcode.com/en/problem/intersection-of-two-linked-lists/
    Example: The following two linked lists:
		A:          a1 → a2
		                   ↘
		                     c1 → c2 → c3
		                   ↗            
		B:     b1 → b2 → b3
    Solution: Longer size minus short size, and move together, until meet same node or meet null.
    Source: https://github.com/kamyu104/LintCode/blob/master/C++/intersection-of-two-linked-lists.cpp
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        ListNode *curA = headA, *curB = headB;
        ListNode *begin = nullptr, *tailA = nullptr, *tailB = nullptr;
        while (curA && curB) {
            if (curA == curB) {
                begin = curA;
                break;
            }
   
            if (curA->next) {
                curA = curA->next;
            } else if (!tailA) {
                tailA = curA;
                curA = headB;
            } else {
                break;
            }

            if (curB->next) {
                curB = curB->next;
            } else if (!tailB) {
                tailB = curB;
                curB = headA;
            } else {
                break;
            }
        }
        
        return begin;
    }
};