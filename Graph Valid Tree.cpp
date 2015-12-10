/*
	Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
	(each edge is a pair of nodes), write a function to check whether 
	these edges make up a valid tree.
	Link: http://www.lintcode.com/en/problem/graph-valid-tree/#
	Example: Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
	Solution: the key step is to find the cycle in this tree, and if there no cycle,
	result is true.
	Source from: https://github.com/kamyu104/LintCode/blob/master/C++/graph-valid-tree.cpp
*/

class Solution {
public:
    struct node {
        int parent = -1;
        vector<int> neighbors;
    };

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        } else if (n == 1) {
            return true;
        }

        /*
		unordered_map<Key,T>::iterator it;
		(*it).first;             // the key value (of type Key)
		(*it).second;            // the mapped value (of type T)
		(*it);                   // the "element value" (of type pair<const Key,T>) 
        */
        unordered_map<int, node> nodes;
        for (const auto& edge : edges) {
        	// emplace: insert a node at end of vector
            nodes[edge.front()].neighbors.emplace_back(edge.back());
            nodes[edge.back()].neighbors.emplace_back(edge.front());
            // front() Returns a reference to the first element in the containers.
            // back()  Returns a reference to the last element in the containers.
        }

        if (nodes.size() != n) {
            return false;
        }

        unordered_set<int> visited;
        queue<int> q;
        q.emplace(0);
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            visited.emplace(i);
            for (const auto& node : nodes[i].neighbors) {
                if (node != nodes[i].parent) {
                    if (visited.find(node) != visited.end()) {
                        return false;
                    } else {
                    	// emplace: insert a node
                        visited.emplace(node);
                        nodes[node].parent = i;
                        q.emplace(node);
                    }
                }
            }
        }
        return visited.size() == n;
    }
};