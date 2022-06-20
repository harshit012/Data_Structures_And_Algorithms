/*
Link: https://leetcode.com/problems/maximal-rectangle/
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& temp) {
        int m=temp.size();
        int n=temp[0].size();
        int maxArea=-1;
        vector<vector<int>> matrix(m,vector<int>(n,0));
        for(int e=0;e<m;e++)
        {
            for(int f=0;f<n;f++)
            {
                matrix[e][f]=(temp[e][f]=='1')?1:0;
            }
        }
        
        for(int e=0;e<m;e++)
        {
            for(int f=0;e!=0 && f<n;f++)
            {
                if(matrix[e][f]!=0) matrix[e][f]+=matrix[e-1][f];
            }
            list<int> stack;
            int store[n];
            for(int f=0;f<n;f++)
            {
                if(stack.size()==0)
                {
                    stack.push_back(f);
                    store[f]=f;
                }
                else
                {
                    while(stack.size()!=0 && matrix[e][stack.back()]>=matrix[e][f]) stack.pop_back();
                    if(stack.size()==0) store[f]=0;
                    else  store[f]=stack.back()+1;
                    stack.push_back(f);
                }
            }
            stack.clear();
            for(int f=n-1;f>=0;f--)
            {
                if(stack.size()==0)
                {
                    stack.push_back(f);
                    store[f]=f-store[f]+1;
                }
                else
                {
                    while(stack.size()!=0 && matrix[e][stack.back()]>=matrix[e][f]) stack.pop_back();
                    if(stack.size()==0) store[f]=n-store[f];
                    else store[f]=(stack.back()-1)-store[f]+1;
                    stack.push_back(f);
                }
                int area=store[f]*matrix[e][f];
                if(area>maxArea) maxArea=area;
            }
            
        }
        return maxArea;
    }
};