/*Description
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


Approach:BFS
1.Create a queue to perform BFS and a visited array to keep track of the cells that have already been processed.
2.Initialize a variable fresh to count the number of fresh oranges in the grid.
3.Traverse the grid and for each cell:
   - If it contains a fresh orange (value 1), increment the fresh count.
   - If it contains a rotten orange (value 2), add its coordinates and the current time (0) to the queue and mark it as visited.
4.Initialize a variable time to keep track of the elapsed time.
5.Perform BFS until the queue is empty:
   - Dequeue the front element from the queue, which contains the coordinates of a rotten orange and the current time.
   - Update the time variable to the maximum of its current value and the time of the dequeued element.
   - For each of the 4 possible directions (up, down, left, right), check if the adjacent cell is within bounds, has not been visited, and contains a fresh orange. If so:
     - Mark it as visited.
     - Add its coordinates and the incremented time to the queue.
     - Decrement the fresh count.
6.After the BFS completes, check if there are any fresh oranges left (fresh > 0). If so, return -1, indicating that it is impossible to rot all oranges. Otherwise, return the elapsed time
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<pair<int,int>,int>> q;

        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) fresh++;

                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
            }
        }

        int time=0;
        int downrow[]={0,-1,1,0};
        int downcol[]={1,0,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);
            for(int k=0;k<4;k++){
                int nrow=r+downrow[k];
                int ncol=c+downcol[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                    fresh--;
                }
            }

        }
        return (fresh==0) ? time:-1;
        
    }
};