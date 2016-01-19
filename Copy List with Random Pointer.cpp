/*
    A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
	Return a deep copy of the list.

    Link: http://www.lintcode.com/en/problem/copy-list-with-random-pointer/

    Example: None

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/copy-list-with-random-pointer.cpp
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        // insert the copied node after the original one
        for (RandomListNode *cur = head; cur; cur = cur->next->next) {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
        }

        // update random node
        for (RandomListNode *cur = head; cur; cur = cur->next->next) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
        }

        // seperate the copied nodes from original ones
        RandomListNode dummy(INT_MIN);
        for (RandomListNode *cur = head, *copy_cur = &dummy;
             cur;
             copy_cur = copy_cur->next, cur = cur->next) {
            copy_cur->next = cur->next;
            cur->next = cur->next->next;
        }

        return dummy.next;
    }
};