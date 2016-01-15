/*
    In data structure Hash, hash function is used to convert a string(or any other type) into an integer smaller than hash 
    size and bigger or equal to zero. The objective of designing a hash function is to "hash" the key as unreasonable as 
    possible. A good hash function can avoid collision as less as possible. A widely used hash function algorithm is using 
    a magic number 33, consider any string as a 33 based big integer like follow:

		hashcode("abcd") = (ascii(a) * 333 + ascii(b) * 332 + ascii(c) *33 + ascii(d)) % HASH_SIZE 

		                              = (97* 333 + 98 * 332 + 99 * 33 +100) % HASH_SIZE

		                              = 3595978 % HASH_SIZE

	here HASH_SIZE is the capacity of the hash table (you can assume a hash table is like an array with index 0 ~ HASH_SIZE-1).
	Given a string as a key and the size of hash table, return the hash value of this key.f

    Link: http://www.lintcode.com/en/problem/hash-function/

    Example: For key="abcd" and size=100, return 78

    Solution: Remember to avoid number over range.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/hash-function.cpp
*/

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        long long value = 0L;
        for (const auto& c : key) {
            value = value * 33L % HASH_SIZE;
            value = (value + static_cast<const long long>(c) % HASH_SIZE) % HASH_SIZE;
        }
        return static_cast<int>(value);
    }
};