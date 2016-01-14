/*
    Given a matrix of lower alphabets and a dictionary. Find all words in the dictionary that can be found in the matrix. 
    A word can start from any position in the matrix and go left/right/up/down to the adjacent position. 

    Link: http://www.lintcode.com/en/problem/word-search-ii/

    Example: Given matrix:

		doaf
		agai
		dcan
		
		and dictionary:
		{"dog", "dad", "dgdg", "can", "again"}

		return {"dog", "dad", "can", "again"}

    Solution: In this method, we search the word based on given dict. In order to finish this task, we maintain a visited
    matrix to perform dfs search. In order to achieve the goal, we should use recursion to test result.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/word-search-ii.cpp
*/

class Solution {
    
private:
    struct TrieNode {
        bool isString = false;
        unordered_map<char, TrieNode *> leaves;

        bool Insert(const string& s) {
            auto* p = this;
            for (const auto& c : s) {

            	// cent(): return const_iterator to end,
            	// A const_iterator is an iterator that points to const content. This iterator  can be increased and decreased 
            	// (unless it is itself also const), just like the iterator returned by vector::end, but it cannot be used to 
            	// modify the contents it points to, even if the vector object is not itself const.
                if (p->leaves.find(c) == p->leaves.cend()) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
            }

            // s already existed in this trie.
            if (p->isString) {
                return false;
            } else {
                p->isString = true;
                return true;
            }
        }

        ~TrieNode() {
            for (auto& kv : leaves) {
                if (kv.second) {
                    kv.second->~TrieNode();
                }
            }
        }
    };    

public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        unordered_set<string> ret;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        string cur;
        TrieNode trie;
        for (const auto& word : words) {
            trie.Insert(word);
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                wordSearchDFS(board, visited, &trie, i, j, cur,  ret);
            }
        }

        return vector<string>(ret.begin(), ret.end());
    }

    void wordSearchDFS(vector<vector<char>> &grid,
             vector<vector<bool>> &visited,
             TrieNode *trie,
             int i,
             int j,
             string cur,
             unordered_set<string> &ret) {
        // Invalid state.
        if (!trie || i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }

        // Not in trie or visited.
        if (!trie->leaves[grid[i][j] ] || visited[i][j]) {
            return;
        }

        // Get next trie nodes.
        TrieNode *nextNode = trie->leaves[grid[i][j]];

        // Update current string.
        cur.push_back(grid[i][j]);

        // Find the string, add to the answers.
        if (nextNode->isString) {
            ret.insert(cur);
        }

        // Marked as visited.
        visited[i][j] = true;

        // Try each curtion.
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        for (const auto& d : directions) {
            wordSearchDFS(grid, visited, nextNode,
                          i + d.first, j + d.second, cur, ret);
        }

        visited[i][j] = false;
    }
};