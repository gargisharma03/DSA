/* Description

There are n cities. Some cities are directly connected, while others are not. If city A is directly connected to city B, and city B is directly connected to city C, then city A is indirectly connected to city C.

A province is a group of cities that are directly or indirectly connected to each other, with no connections to any city outside the group.

You are given an n × n adjacency matrix isConnected, where:

isConnected[i][j] = 1 indicates that city i and city j are directly connected.
isConnected[i][j] = 0 indicates that they are not directly connected.

Return the total number of provinces.

Approach: Using DFS Traversal

The problem can be solved by finding the number of **connected components** in the graph using **Depth First Search (DFS)**.

1.Create a visited array to keep track of the cities that have already been explored.
2.Initialize a variable count = 0 to store the number of provinces.
3.Traverse all the cities one by one.
4.If a city has not been visited, start a DFS from that city. The DFS will visit all cities that are directly or indirectly connected to it, marking them as visited.
5.After the DFS completes, increment count by 1, as one entire province has been explored.
6.Continue this process until all cities have been visited.
Finally, return count, which represents the total number of provinces.
Time Complexity:O(n²)
Space Complexity:O(n)
 */

#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>&isvisited){
        isvisited[node]=1;

        for(int neigh=0;neigh<isConnected.size();neigh++){
            if(isConnected[node][neigh]==1 && !isvisited[neigh]){
                dfs(neigh,isConnected,isvisited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> isvisited(n, 0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!isvisited[i]){
                dfs(i,isConnected,isvisited);
                count++;
            }
        }
        return count;
    }
};