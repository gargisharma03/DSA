/* Description:
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 Approach: BFS
 1.Edge case: if the new color is same as the original color,return the image.
 2.Then store the original color and update the starting pixel with the new color.
 3.Create a queue to perform BFS and push the starting pixel into it.
 4.Define the possible directions for moving to adjacent pixels (up, down, left, right).
 5.Perform BFS until the queue is empty:
   - Dequeue the front pixel from the queue.
   - For each of the 4 possible directions, calculate the coordinates of the adjacent pixel.
   - Check if the adjacent pixel is within bounds and has the same color as the original color. If so:
     - Update its color to the new color.
     - Push it into the queue for further processing.

*/


#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
#include <queue>

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int change=image[sr][sc];

        if(color==change){
            return image;
        }

        int rows = image.size();
        int cols = image[0].size();

        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=r+delRow[i];
                int ncol=c+delCol[i];

                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && image[nrow][ncol] == change) {
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }

        }

        return image;


        
    }
};