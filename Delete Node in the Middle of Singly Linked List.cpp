/*
    Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.
    Link: http://www.lintcode.com/en/problem/delete-node-in-the-middle-of-singly-linked-list/
    Example: Given 1->2->3->4, and node 3. return 1->2->4
    Solution: In C++. we can access to this node directly.
    Source: https://github.com/kamyu104/LintCode/blob/master/C++/delete-node-in-the-middle-of-singly-linked-list.cpp
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if (!node || !node->next) {
            return;
        }
        auto node_to_delete = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete node_to_delete;
    }
};