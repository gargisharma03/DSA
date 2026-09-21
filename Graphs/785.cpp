/*
Question:
Is graph bipartite?
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

Approach:

1.The main idea behind a bipartite graph is that if there are no odd cycles present in the graph, it is bipartite.
2.So we use color coding. We go through each and every node and initially mark them as 0 (not colored). Since the graph may not be connected, we need to check every node and start a BFS whenever we find an uncolored node.
3.Using BFS, we move to all the neighbours of the current node. If a neighbour is not colored, we give it the opposite color of the current node. We use 3 - currentNodeColor to switch between colors 1 and 2.
4.If the neighbour is already colored, we check whether it has the same color as the current node. Since they are directly connected, they must have different colors. If they have the same color, there is a coloring conflict, which means the graph is not bipartite, so we return false.
5.If we are able to color all the nodes without any conflict, the graph is bipartite, so we return true.
6.We use BFS because it allows us to propagate the two colors level by level through the graph.

Time:  O(V + E)
Space: O(V)

*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        // 0 = not colored
        // 1 = group 1
        // 2 = group 2
        vector<int> color(graph.size(), 0);

        for(int i = 0; i < graph.size(); i++) {

            if(color[i] != 0)
                continue;

            color[i] = 1;

            queue<int> q;
            q.push(i);

            while(!q.empty()) {

                int node = q.front();
                q.pop();

                for(int neighbor : graph[node]) {
                    if(color[neighbor]==0) {
                        color[neighbor] = 3-color[node];
                        q.push(neighbor);
                    }
                    else {
                        if(color[node]==color[neighbor])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};