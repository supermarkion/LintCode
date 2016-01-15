/*
    The size of the hash table is not determinate at the very beginning. If the total size of keys is too large 
    (e.g. size >= capacity / 10), we should double the size of the hash table and rehash every keys. Say you have 
    a hash table looks like below:

		size=3, capacity=4

		[null, 21, 14, null]
		       ↓    ↓
		       9   null
		       ↓
		      null

	The hash function is:
		int hashcode(int key, int capacity) {
		    return key % capacity;
		}
	here we have three numbers, 9, 14 and 21, where 21 and 9 share the same position as they all have the same 
	hashcode 1 (21 % 4 = 9 % 4 = 1). We store them in the hash table by linked list. rehashing this hash table, 
	double the capacity, you will get:

		size=3, capacity=8

		index:   0    1    2    3     4    5    6   7
		hash : [null, 9, null, null, null, 21, 14, null]

	Given the original hash table, return the new hash table after rehashing .

    Link: http://www.lintcode.com/en/problem/rehashing/

    Example: Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.

    Solution: None (You can use function: a % b = (a % b + b) % b to make it is a non negative integer.)

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/rehashing.cpp
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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        const int old_size = hashTable.size();
        const int new_size = old_size * 2;
        if (old_size == 0) {
            return hashTable;
        }
        vector<ListNode*> rehashTable(new_size, nullptr);
        for (int i = 0; i < old_size; ++i) {
            if (hashTable[i] != nullptr) {
                rehash(hashTable, rehashTable, i);
            }
        }
        return rehashTable;
    }
    
    void rehash(vector<ListNode*>& hashTable, vector<ListNode*>& rehashTable, int i) {
        const int new_size = rehashTable.size();
        ListNode *curr = hashTable[i];
        while (curr != nullptr) {
            int val = curr->val;
            int new_pos = (val % new_size + new_size) % new_size;
            if (rehashTable[new_pos] == nullptr) {
                rehashTable[new_pos] = new ListNode(val);
            } else {
                ListNode *tmp = rehashTable[new_pos];
                while (tmp->next != nullptr) {
                    tmp = tmp->next; // move to the end of this pos
                }
                tmp->next = new ListNode(val);
            }
            curr = curr->next;
        }
    }
};
