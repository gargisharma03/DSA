/*
Description:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Approach: BFS
1. Created a vsited array for marking the visited cells.
2. Traverse the grid and for each cell:
   - If it contains a land (value '1') and has not been visited, start a BFS from that cell. The BFS will visit all cells that are directly or indirectly connected to it, marking them as visited.
   - After the BFS completes, increment count by 1, as one entire island has been explored.
3.Carried out bfs->declaring a queue and push the starting cell into it and mark it as visited.
4.While the queue is not empty, dequeue the front cell and for each of the 4 possible directions (up, down, left, right), check if the adjacent cell is within bounds, has not been visited, and contains a land. If so:
   - Mark it as visited.
   - Add its coordinates to the queue for further processing.

*/
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    void bfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<int>>& visited, int n, int m) {

        queue<pair<int,int>> q;
        q.push({r,c});
        visited[r][c] = 1;

        int drow[] = {0,0,1,-1};
        int dcol[] = {1,-1,0,0};

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            for(int k=0;k<4;k++) {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                   grid[nrow][ncol]=='1' && !visited[nrow][ncol]) {

                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));

        int islands = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]=='1' && !visited[i][j]) {
                    bfs(i,j,grid,visited,n,m);
                    islands++;
                }
            }
        }

        return islands;
    }
};