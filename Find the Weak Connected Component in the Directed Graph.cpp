/*
    Find the number Weak Connected Component in the directed graph. Each node in the graph
    contains a label and a list of its neighbors. (a connected set of a directed graph is a
    subgraph in which any two vertices are connected by direct edge path.)
    Link: http://www.lintcode.com/en/problem/find-the-weak-connected-component-in-the-directed-graph/
    Example: Given graph:
    A------B    C
     \     |    |
      \    |    |
       \   |    |
        \  v    v
         ->D    E <- F
    Return {A,B,D}, {C,E,F}. Since there are two connected component which are {A,B,D} and {C,E,F}
    Solution: In this problem, we define a class named UnionFind, and use to to speed up process on find node.
    Source: http://yucoding.blogspot.com.au/2015/07/leetcode-question-add-and-search-word.html
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
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        sort(nodes.begin(), nodes.end(),
            [](const DirectedGraphNode* a, const DirectedGraphNode* b) {
                return a->label < b->label;
            });
        unordered_map<int, int> set;
        
        // put all nodes in the disjoint-set
        for (const auto& node : nodes) {
            set[node->label] = node->label;
        }
        
        // union-find each edage
        for (const auto& node : nodes) {
            for (const auto& neighbour : node->neighbors) {
                union_set(&set, node->label, neighbour->label);
            }
        }
        
        unordered_map<int, vector<int>> group;
        for (const auto& node : nodes) {
            group[find_set(node->label, &set)].emplace_back(node->label);
        }
        
        // Sort elements in each group
        vector<vector<int>> result;
        for (auto& kvp : group) {   // kvp means key-value pair
            result.emplace_back(move(kvp.second));
        }
        return result;
    }
    
    int find_set(int x, unordered_map<int, int> *set) {
        if ((*set)[x] != x) {
            (*set)[x] = find_set((*set)[x], set);
        }
        return (*set)[x];
    }
    
    void union_set(unordered_map<int, int> *set, int x, int y) {
        int x_root = find_set(x, set), y_root = find_set(y, set);
        (*set)[min(x_root, y_root)] = max(x_root, y_root);
    }
};