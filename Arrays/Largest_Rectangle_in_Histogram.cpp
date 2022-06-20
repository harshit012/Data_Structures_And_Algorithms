/*
Link : https://leetcode.com/problems/largest-rectangle-in-histogram/

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
            list<int> stack;
            int n=heights.size();
            int store[n];
            int maxArea=0;
            for(int f=0;f<n;f++)
            {
                if(stack.size()==0)
                {
                    stack.push_back(f);
                    store[f]=f;
                }
                else
                {
                    while(stack.size()!=0 && heights[stack.back()]>=heights[f]) stack.pop_back();
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
                    while(stack.size()!=0 && heights[stack.back()]>=heights[f]) stack.pop_back();
                    if(stack.size()==0) store[f]=n-store[f];
                    else store[f]=(stack.back()-1)-store[f]+1;
                    stack.push_back(f);
                }
                int area=store[f]*heights[f];
                if(area>maxArea) maxArea=area;
            }
        return maxArea;
    }
};