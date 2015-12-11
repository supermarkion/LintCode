/*
	Implement a function to check if a linked list is a palindrome.
	Link: http://www.lintcode.com/en/problem/palindrome-linked-list/
	Example: Given 1->2->1, return true
	Solution: reverse first half of list, and then compare with second half of list. We also apply
	fast and slow pointers to find the middle of this list.
	Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/palindrome-linked-list.cpp
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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        // nullptr is a pointer literal of type std::nullptr_t
        ListNode *reverse = nullptr, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            const auto head_next = head->next;
            head->next = reverse;
            reverse = head;
            head = head_next;
        }
        
        ListNode *tail = fast ? head->next : head;
        
        bool is_palindrome = true;
        while (reverse) {
            is_palindrome = is_palindrome && reverse->val == tail->val;
            const auto reverse_next = reverse->next; // temp node
            reverse->next = head;
            head = reverse;
            reverse = reverse_next;
            tail = tail->next;
        }
        return is_palindrome;
    }
};