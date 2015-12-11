/*
    Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
    If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
    You may not alter the values in the nodes, only nodes itself may be changed.
    Only constant memory is allowed.
    Link: http://www.lintcode.com/en/problem/reverse-nodes-in-k-group/
    Example: 
    Given this linked list: 1->2->3->4->5
    For k = 2, you should return: 2->1->4->3->5
    For k = 3, you should return: 3->2->1->4->5
    Solution: Divided list to several k-groups, and reverse each group.
    Source: http://yucoding.blogspot.com.au/2015/07/leetcode-question-add-and-search-word.html
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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
        ListNode dummy = ListNode(numeric_limits<int>::min());
        dummy.next = head;
        ListNode *cur = head, *cur_dummy = &dummy;
        int length = 0;
        
        while (cur) {
            ListNode *next_cur = cur->next;
            length = (length + 1) % k;
            
            if (length == 0) {
                ListNode *next_dummy = cur_dummy->next;
                reverse(&cur_dummy, cur->next);
                cur_dummy = next_dummy;
            }
            cur = next_cur;
        }
        return dummy.next;
    }
    
    // template on reverse a linked list
    void reverse(ListNode **begin, const ListNode *end) {
            ListNode *first = (*begin)->next;
            ListNode *cur = first->next;
            
            while (cur != end) {
                first->next = cur->next;
                cur->next = (*begin)->next;
                (*begin)->next = cur;
                cur = first->next;
            }
    }
};