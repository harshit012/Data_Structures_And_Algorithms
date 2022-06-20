/*
Link : https://leetcode.com/problems/game-of-life/
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.

*/

class Solution {
public:
    bool isValid(int e,int f,int m,int n)
    {
        if(e<0 || e>=m || f<0 || f>=n)  return false;
        return true;
    }
    
    int countIt(vector<vector<int>>& store,int e,int f,int m,int n)
    {
        int cc=0;
        if(isValid(e+1,f,m,n) && store[e+1][f]) cc++;
        if(isValid(e-1,f,m,n) && store[e-1][f]) cc++;
        if(isValid(e,f+1,m,n) && store[e][f+1]) cc++;
        if(isValid(e,f-1,m,n) && store[e][f-1]) cc++;
        if(isValid(e+1,f+1,m,n) && store[e+1][f+1]) cc++;
        if(isValid(e+1,f-1,m,n) && store[e+1][f-1]) cc++;
        if(isValid(e-1,f+1,m,n) && store[e-1][f+1]) cc++;
        if(isValid(e-1,f-1,m,n) && store[e-1][f-1]) cc++;
        return cc;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> store(m,vector<int>(n,0));
        for(int e=0;e<m;e++)
        {
            for(int f=0;f<n;f++)
            {
                int count=countIt(board,e,f,m,n);
                if(count<2) store[e][f]=0;
                else if(count==2) store[e][f]=board[e][f];
                else if(count==3) store[e][f]=1;
                else store[e][f]=0;
            }
        }
        for(int e=0;e<m;e++)
        {
            for(int f=0;f<n;f++)
            {
                board[e][f]=store[e][f];
            }
        }
    }
};