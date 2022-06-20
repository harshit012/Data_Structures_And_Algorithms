/*
Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int result=0;
        int sum=0;
        unordered_map<int,int> umap;
        umap[0]=1;
        for(int e=0;e<n;e++)
        {
            sum+=nums[e];
            int r=sum%k;
            if(r<0) r+=k;
            result+=umap[r];
            umap[r]++;
        }
        return result;
    }
};