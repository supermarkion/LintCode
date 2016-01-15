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
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if (start == end) {
            return 1;
        }
        int n = start.size();
        if (n < 1 || n != end.size()) {
            return 0;
        }
 
        queue<string> Q;
        Q.push(start);
        dict.erase(start);
        int length = 2;
 
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                string word = Q.front(); Q.pop();
                for (int i = 0; i < n; i++) {
                    char oldChar = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == oldChar) continue;
                        word[i] = c;
                        if (word == end) {
                            return length;
                        }
                        if (dict.find(word) != dict.end()) {
                            Q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = oldChar;
                }
            } // for size
            length++;
        }
        return 0;
    }
};