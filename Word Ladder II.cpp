/*
    Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
		Only one letter can be changed at a time
		Each intermediate word must exist in the dictionary
    
    Link: http://www.lintcode.com/en/problem/word-ladder/

    Example: Given:
    	start = "hit"
		end = "cog"
		dict = ["hot","dot","dog","lot","log"]
		As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
		return its length 5.

    Solution: Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from 
    start to end. We apply BFS to solve. It contains following steps:
		• construct a queue, and a hash to save passed node word
		• use a method named getNextWords to get the neighbour word list based on current word.
		• it we passed this word, ignore it.

    Source: http://www.jiuzhang.com/solutions/word-ladder/
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        unordered_map<string, unordered_set<string>> trace;

        // BFS, each round is a level
        unordered_set<string> levels[2];
        int cur_level = 0;

        levels[cur_level].emplace(start);
        while (dict.size() > 0 && levels[cur_level % 2].size() > 0) {
            // end is in current level, stop
            if (trace.count(end) == 1) {
                ++cur_level;
                break;
            }

            // clear words from the dictionary to avoid it' apear in future level again
            for (auto& word : levels[cur_level % 2]) {
                dict.erase(word);
            }

            levels[(cur_level + 1) % 2].clear();
            for (auto& from : levels[cur_level % 2]) {
                string new_word = from;
                for (int i = 0; i < new_word.length(); ++i) {
                    char orig_c = from[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        new_word[i] = c;
                        if (dict.count(new_word) == 1) {
                            trace[new_word].emplace(from);
                            levels[(cur_level + 1) % 2].emplace(new_word);
                        }
                    }
                    new_word[i] = orig_c;
                }
            }

            ++cur_level;
        }

        vector<vector<string>> result;
        vector<string> temp;
        traceBack(trace, temp, end, result);
        return result;
    }

    void traceBack(unordered_map<string, unordered_set<string>> &trace,
                   vector<string> &temp,
                   string end,
                   vector<vector<string>> &result) {
        temp.emplace_back(end);
        if (trace.count(end) != 1) {
            vector<string> path = temp;
            reverse(path.begin(), path.end());
            result.emplace_back(move(path));
        }
        else {
            for (auto& word: trace[end]) {
                traceBack(trace, temp, word, result);
            }
        }
        temp.pop_back();
    }
};