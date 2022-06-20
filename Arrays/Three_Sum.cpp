/*
Link : https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     set<vector<int>> s;
         vector<vector<int>> m;
        if(nums.size()<3)
            return m;
            
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 &&nums[i]==nums[i-1])
                continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                    k--;
                else
                    j++;
            }
        }
       
        for(auto i:s)
            m.push_back(i);
        return m;
    }
};