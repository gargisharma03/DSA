/*
Description:
Given a 2D grid of 0s and 1s, return the number of "enclaves" (connected components of 1s that are completely surrounded by 0s and not touching the edges of the grid).

Approach: BFS
1. Start by identifying all 1s on the edges of the grid.
2. Perform a BFS from each of these edge 1s, marking all connected 1s as visited (by changing their value to 2).
3. After processing all edge-connected components, count the remaining 1s in the grid, which represent the enclaves.

*/
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int enclaves=0;

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                grid[i][0]=2;
            }
            if(grid[i][n-1]==1){
                q.push({i,n-1});
                grid[i][n-1]=2;
            }
        }

        
        for(int j=0;j<n;j++){
            if(grid[0][j]==1){
                q.push({0,j});
                grid[0][j]=2;
            }
            if(grid[m-1][j]==1){
                q.push({m-1,j});
                grid[m-1][j]=2;
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int drow[]={1,-1,0,0};
            int dcol[]={0,0,1,-1};

            for(int k=0;k<4;k++){
                int nrow=r+drow[k];
                int ncol=c+dcol[k];

                if(nrow<m && nrow>=0 && ncol<n && ncol>=0
                && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({nrow,ncol});
                }
            }

        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    enclaves++;
                }
            }
        }
        return enclaves;
    }
};