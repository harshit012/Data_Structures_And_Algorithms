/*
Link : https://leetcode.com/problems/word-search/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

*/

class Solution {
public:
    int m,n;
    bool is_valid_index(int a,int b)
    {
        if(a<0||b<0||a>=m||b>=n)
        {
            return false;
        }
        return true;
    }
    bool is_exist(vector<vector<char>>& board, string &word,vector<vector<bool>> &visited,int x,int y,int index)
    {
        if(index>=word.size()) return true;
        if(!is_valid_index(x,y)) return false;
        if(board[x][y]!=word[index]) return false;
        if(board[x][y]=='$') return false;
        char cc=board[x][y];
        board[x][y]='$';
        bool a=is_exist(board,word,visited,x+1,y,index+1);
        bool b=is_exist(board,word,visited,x-1,y,index+1);
        bool c=is_exist(board,word,visited,x,y+1,index+1);
        bool d=is_exist(board,word,visited,x,y-1,index+1);
        board[x][y]=cc;
        return a||b||c||d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->m=board.size();
        if(m==0) return false;
        this->n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int e=0;e<m;e++)
        {
            for(int f=0;f<n;f++)
            {
                if(board[e][f]==word[0])
                {
                    bool check=is_exist(board,word,visited,e,f,0);
                    if(check) return true;
                }
            }
        }
        return false;
    }
};