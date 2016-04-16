/*
    Given a nested list of integers, implement an iterator to flatten it.
	
	Each element is either an integer, or a list -- whose elements may also be integers or other lists.

    Link: http://www.lintcode.com/en/problem/flatten-nested-list-iterator/

    Example: 
    	Given the list [[1,1],2,[1,1]], By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
		Given the list [1,[4,[6]]], By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

    Solution: None

    Source: http://www.cnblogs.com/grandyang/p/5358793.html
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            s.push(nestedList[i]);
        }
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        NestedInteger t = s.top(); 
        s.pop();
        return t.getInteger();
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
         while (!s.empty()) {
            NestedInteger t = s.top(); 
            if (t.isInteger()) {
                return true;
            }
            s.pop();
            for (int i = t.getList().size() - 1; i >= 0; --i) {
                s.push(t.getList()[i]);
            }
        }
        return false;
    }
    
private:
    stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */