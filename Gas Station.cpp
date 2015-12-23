/*
    There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
	You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to 
	its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
	Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

    Link: http://www.lintcode.com/en/problem/gas-station/

    Example: Given 4 gas stations with gas[i]=[1,1,3,1], and the cost[i]=[2,2,1,1]. The starting gas station's index is 2.

    Solution: In this problem, it has a main point that it may not exist the solution, which means that no matter where we 
    start our car, the total gas is less than total cost. Then, we use a variables named total to make a decision on 
    available solution. Moreover, it the current sum is greater than 0, then the start index is index plus one (because 
    last time cause error, and assign this index).

    Source: https://github.com/kamyu104/LintCode/blob/master/C++/gas-station.cpp
*/

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int current_sum = 0;
        int total_sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            current_sum += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
            if (current_sum < 0) {
                // It means any gas station in range [start, i] cannot be start.
                current_sum = 0;
                start = i + 1;
            }
        }

        // Check if solution exists, i.e. sum(gas) >= sum(cost).
        if (total_sum >= 0) {
            // 1. route of [start, len(gas) - 1] must be positive
            // 2. route of [0, start - 1] must be negative
            // 3. sum(gas) >= sum(cost), so 1 + 2 >= 0
            // According to the above, start is the gas station we want.
            return start;
        }

        return -1;
    }
};