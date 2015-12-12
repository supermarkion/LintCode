/*
    Implement a trie with insert, search, and startsWith methods.
    Link: http://www.lintcode.com/en/problem/implement-trie/
    Example: You may assume that all inputs are consist of lowercase letters a-z.
    Solution: This is a typical data structure problem, and we save each node as a bool value to
    label this character is a end of a word, and also use a map to sae all neighbour nodes.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/implement-trie.cpp
*/

 /**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    bool is_string;
    unordered_map<char, TrieNode *> leaves;
    // Initialize your data structure here.
    TrieNode() {
        is_string = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for (const auto& c : word) {
            if (!cur->leaves.count(c)) {
                cur->leaves[c] = new TrieNode();
            }
            cur = cur->leaves[c];
        }
        cur->is_string = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = childSearch(word);
        if (node) {
            return node->is_string;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return childSearch(prefix);
    }
    
    TrieNode * childSearch(const string& word) {
        TrieNode *cur = root;
        for (const auto& c : word) {
            if (cur->leaves.count(c)) {
                cur = cur->leaves[c];
            } else {
                return nullptr;
            }
        }
        return cur;
    }

private:
    TrieNode* root;
};