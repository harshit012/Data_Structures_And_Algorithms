/*
Link : https://leetcode.com/problems/spiral-matrix/

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int top,left,right,down;
        top=left=0;
        right=n-1;
        down=m-1;
        int dir=0;
        int total=m*n;
        vector<int> result(total);
        int index=0;
        for(int count=1;count<=total;)
        {
            if(dir==0)
            {
                for(int e=left;e<=right;e++)
                {
                    result[index++]=matrix[top][e];
                    count++;
                }
                top+=1;
                dir+=1;
            }
            else if(dir==1)
            {
                for(int e=top;e<=down;e++)
                {
                    result[index++]=matrix[e][right];
                    count++;
                }
                right--;
                dir+=1;
            }
            else if(dir==2)
            {
                for(int e=right;e>=left;e--)
                {
                    result[index++]=matrix[down][e];
                    count++;
                }
                down--;
                dir+=1;
            }
            else
            {
                for(int e=down;e>=top;e--)
                {
                    result[index++]=matrix[e][left];
                    count++;
                }
                left++;
                dir+=1;
                dir=dir%4;
            }
        }
        return result;
    }
};