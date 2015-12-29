/*
    Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

    Link: http://www.lintcode.com/en/problem/route-between-two-nodes-in-graph/

    Example: Given graph:
		A----->B----->C
		 \     |
		  \    |
		   \   |
		    \  v
		     ->D----->E
		for s = B and t = E, return true
		for s = D and t = C, return false

    Solution: None

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/route-between-two-nodes-in-graph.cpp
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        unordered_set<DirectedGraphNode *> visited_node;
        visited_node.emplace(s);
        return DFS(s, t, visited_node);
    }
    bool DFS(DirectedGraphNode* s, const DirectedGraphNode* t,
             unordered_set<DirectedGraphNode *> &visited_node) {
        if (s == t) {
            return true;
        }

        // Search neighbors which are not visted
        for (const auto& node: s->neighbors) {
            if (visited_node.emplace(node).second) {
                if (DFS(node, t, visited_node)) {
                    return true;
                }
                //visited_node.erase(node);
            }
        }
        return false;
    }
};

