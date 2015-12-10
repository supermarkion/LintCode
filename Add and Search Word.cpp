/*
    Design a data structure that supports the following two operations:

    void addWord(word)
    bool search(word)

    search(word) can search a literal word or a regular expression string
    containing only letters a-z or .. A . means it can represent any one letter.

    Link: http://www.lintcode.com/en/problem/add-and-search-word/
    Example: 
    
    addWord("bad")
    addWord("dad")
    addWord("mad")
    search("pad") -> false
    search("bad") -> true
    search(".ad") -> true
    search("b..") -> true

    Solution: use a Trie (tree) to implement,and speed up search process.
    Source: http://yucoding.blogspot.com.au/2015/07/leetcode-question-add-and-search-word.html
*/

class TrieNode {
public:
    TrieNode(){
        value = 0;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
    int value;
    TrieNode* children[26];
};
 
 
class WordDictionary {
private:
    TrieNode* trie;
    int count;
public:
 
    // Constructor
    WordDictionary(){
        trie = new TrieNode();
        count  = 0;
    }
     
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = trie;
        int l = word.size();
        for (int i = 0; i < l; i++){
            int idx = word[i] - 'a';
            if (!p->children[idx]){
                p->children[idx] = new TrieNode();
            }
            p = p->children[idx];
        }
        p->value = ++count;
    }
 
 
    bool search2(string &word, int pos, TrieNode* p) {
        if (pos == word.size()){
            return  p->value == 0 ? false: true;
        } else {
            if (word[pos] == '.'){
                for (int j = 0; j < 26; j++){
                    if (p->children[j]){
                        if (search2(word, pos + 1, p->children[j])){
                            return true;
                        }
                    }
                }
                return false;
            } else {
                int idx = word[pos] - 'a';
                if (p->children[idx]){
                    return search2(word, pos + 1, p->children[idx]);
                } else {
                    return false;
                }
            }   
        }
    }
         
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search2(word, 0, trie);
    }
};
 
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");