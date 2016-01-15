/*
    Given an directed graph, a topological order of the graph nodes is defined as follow:
        For each directed edge A -> B in graph, A must before B in the order list.
        The first node in the order can be any node in the graph with no nodes direct to it.
    Find any topological order for the given graph.

    Link: http://www.lintcode.com/en/problem/topological-sorting/

    Example: None

    Solution: In this method, we should use a hash map to save the indegree information of each node, and perform 
    dfs to finish the task.

    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/topological-sorting.cpp
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
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode *> output;

        // Find ancestors of each node by DFS
        unordered_set<DirectedGraphNode *> nodes;
        unordered_map<DirectedGraphNode *, int> ancestors;
        for (const auto& node :graph) {
            findDependencyBFS(node, nodes, ancestors);
        }

        // Output topological order by BFS
        topSortBFS(graph, ancestors, output);

        return output;
    }

private:
    void findDependencyBFS(DirectedGraphNode* node,
                           unordered_set<DirectedGraphNode *> &nodes,
                           unordered_map<DirectedGraphNode *, int> &ancestors) {
        if (nodes.emplace(node).second) {
            queue<DirectedGraphNode *> scheduled;
            scheduled.emplace(node);
            while (!scheduled.empty()) {
                DirectedGraphNode *node = scheduled.front();
                scheduled.pop();

                // Update in degree of neighbors.
                for (const auto& neighbor : node->neighbors) {
                    ++ancestors[neighbor];
                    if (nodes.emplace(neighbor).second) {
                        scheduled.emplace(neighbor);
                    }
                }
            }
        }
    }

    void topSortBFS(vector<DirectedGraphNode*>& graph,
                    unordered_map<DirectedGraphNode *, int> &ancestors,
                    vector<DirectedGraphNode *> &output) {
        // Find the nodes with 0 in degree.
        queue<DirectedGraphNode *> scheduled;
        for (const auto& node : graph) {
            if (ancestors[node] == 0) {
                scheduled.emplace(node);
            }
        }

        while (!scheduled.empty()) {
            DirectedGraphNode *node = scheduled.front();
            output.emplace_back(node);
            scheduled.pop();

            // Update in degree of neighbors.
            for (const auto& neighbor : node->neighbors) {
                --ancestors[neighbor];
                if (ancestors[neighbor] == 0) {
                    scheduled.emplace(neighbor);
                }
            }
        }
    }
};