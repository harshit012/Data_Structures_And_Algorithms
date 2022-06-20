/*
Link: https://leetcode.com/problems/reverse-pairs/

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1

*/

class Solution {
public:
    int merge(vector<int> &nums,int &s,int &mid,int &e)
{
    int ans=0;
    int i=s,j=mid+1,k=0;
    for(i=s;i<=mid;i++)
    {
        while(j<=e&&2LL*nums[j]<nums[i])
        {
            j++;
        }
        ans+=j-(mid+1);
    }
    i=s;j=mid+1;
    vector<int> v(e-s+1);
    while(i<=mid&&j<=e)
    {
        if(nums[i]<nums[j])
        {
            v[k]=nums[i];
            i++;
        }
        else
        {
            v[k]=nums[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        v[k]=nums[i];
        i++;k++;
    }
    while(j<=e)
    {
        v[k]=nums[j];
        k++;j++;
    }
    for(int z=0;z<e-s+1;z++)
    {
        nums[z+s]=v[z];
    }
    return ans;
}

void divide(vector<int> &nums,int s,int e,int &ans)
{
    if(s<e)
    {
        int mid=(s+e)/2;
        divide(nums,s,mid,ans);
        divide(nums,mid+1,e,ans);
        ans+=merge(nums,s,mid,e);
    }
}

int reversePairs(vector<int>& nums) {
    int ans=0;
    divide(nums,0,nums.size()-1,ans);
    return ans;
}
};