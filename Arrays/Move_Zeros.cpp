/*
-
Link:  https://leetcode.com/problems/move-zeroes/
283. Move Zeroes
Easy

9220

245

Add to List

Share
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 
*/

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int a,b;
        a=0;
        b=0;
        int n=arr.size();
        while(a<n && b<n)
        {
            while(b<n && arr[b]==0 )
            {
                b++;
            }
            if(b==n) break;
            int g=arr[a];
            arr[a]=arr[b];
            arr[b]=g;
            a++;
            b++;
        }
    }
};