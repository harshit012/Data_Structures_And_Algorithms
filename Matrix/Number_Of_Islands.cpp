/*
Link: https://leetcode.com/problems/max-area-of-island/

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

class Solution {
public:
    int dfs(vector<vector<int>>& grid,int e,int f,int rowLength,int colLength)
    {
        if(e<0 || f<0 || e>=rowLength || f>=colLength || grid[e][f]!=1) return 0;
        grid[e][f]=2;
        return 1+dfs(grid,e+1,f,rowLength,colLength)+dfs(grid,e-1,f,rowLength,colLength)+dfs(grid,e,f+1,rowLength,colLength)+dfs(grid,e,f-1,rowLength,colLength);
    }
        
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int maxArea=0;
        int rowLength=grid.size();
        int columnLength=grid[0].size();
        for(int e=0;e<rowLength;e++)
        {
            for(int f=0;f<columnLength;f++)
            {
                if(grid[e][f]==1)
                {
                    int area=dfs(grid,e,f,rowLength,columnLength);
                    if(area>maxArea) maxArea=area;
                }
            }
        }
        return maxArea;
    }
};