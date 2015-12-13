/*
    Given a dictionary, find all of the longest words in the dictionary.
    Link: http://www.lintcode.com/en/problem/longest-words/#
    Example: 
    {
    "dog",
    "google",
    "facebook",
    "internationalization",
    "blabla"
    }
    the longest words are(is) ["internationalization"].
    Solution: loop the words in dictionary, and update result vector all the time.
    Source: None
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int maxLength = 0;
        vector<string> result;
        for (const auto& word : dictionary) {
            if (word.size() > maxLength) {
                maxLength = word.size();
                result.clear();
                result.push_back(word);
            } else if (word.size() == maxLength) {
                result.push_back(word);
            }
        }
        return result;
    }
};