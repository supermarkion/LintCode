/*
    Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
	How we serialize an undirected graph: 
		Nodes are labeled uniquely.
	We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

    Link: http://www.lintcode.com/en/problem/clone-graph/

    Example:
    	The graph has a total of three nodes, and therefore contains three parts as separated by #.
		First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
		Second node is labeled as 1. Connect node 1 to node 2.
		Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
		Visually, the graph looks like the following:

		   1
		  / \
		 /   \
		0 --- 2
		     / \
		     \_/

    Solution: Use a map to find copied root nodes.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/clone-graph.cpp
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if (!node) {
            return nullptr;
        }
        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
        copied[node] = new UndirectedGraphNode(node->label);
        queue<const UndirectedGraphNode *> q;
        q.emplace(node);
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            for (const auto& n : node->neighbors) {
                if (copied.find(n) == copied.end()) {
                    copied[n] = new UndirectedGraphNode(n->label);
                    q.emplace(n);
                }

                copied[node]->neighbors.emplace_back(copied[n]);
            }
        }

        return copied[node];
    }
};