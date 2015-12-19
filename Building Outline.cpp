/*
    Given N buildings in a x-axis，each building is a rectangle and can be represented by a triple (start, end, height)，
    where start is the start position on x-axis, end is the end position on x-axis and height is the height of the building. 
    Buildings may overlap if you see them from far away，find the outline of them。An outline can be represented by a triple, 
    (start, end, height), where start is the start position on x-axis of the outline, end is the end position on x-axis and 
    height is the height of the outline.
    Link: http://www.lintcode.com/en/problem/building-outline/
    Example: Given 3 buildings：
    [
	  [1, 3, 3],
	  [2, 4, 4],
	  [5, 6, 1]
	]
	The outlines are：
	[
	  [1, 2, 3],
	  [2, 4, 4],
	  [5, 6, 1]
	]
    Solution: Use priority_queue to solve this problm.
    Source: None
*/

class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        vector<vector<int> > res;
        const int size = 300000;
        int n = buildings.size();
        if(n == 0) {
            return res;
        } 
        sort(buildings.begin(), buildings.end());
        priority_queue<vector<int>> hp;
        
        int bp = 0, cur_h = -1, start = -1;
        vector<int> build = buildings[bp];
        for(int i = 0; i < size; i++){
            while(!hp.empty()){
                if(hp.top()[2] < i) {
                    hp.pop();//height overflow
                } else {
                    break;
                }
            }
            if(!hp.empty()) {
                if(hp.top()[0] == cur_h) {
                    res.back()[1] = i;
                } else {
                    cur_h = hp.top()[0];
                    res.push_back({start,i,cur_h});
                }
            }
            while(bp < n && build[0] == i) {
                hp.push({build[2],build[0],build[1]});
                if(++bp < n) {
                    build = buildings[bp];
                }
            }
            start = i;
        }
        return res;
    }
};
