/*
    There are N children standing in a line. Each child is assigned a rating value.
    You are giving candies to these children subjected to the following requirements:
        Each child must have at least one candy.
        Children with a higher rating get more candies than their neighbors.
    What is the minimum candies you must give?

    Link: http://www.lintcode.com/en/problem/candy/
    Example:
        Given ratings = [1, 2], return 3.
        Given ratings = [1, 1, 1], return 3.
        Given ratings = [1, 2, 2], return 4. ([1,2,1]).
    Solution: When we new vector, we assign 1s.
    Source: None
*/

class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        if (ratings.empty()) {
            return 0;
        }
        vector<int> count(ratings.size(), 1);
        int sum = 0;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 1; i >= 1; i--) {
            sum += count[i];
            if (ratings[i - 1] > ratings[i] && count[i - 1] <= count[i]) {
                count[i - 1] = count[i] + 1;
            }
        }
        sum += count[0];
        return sum;
    }
};