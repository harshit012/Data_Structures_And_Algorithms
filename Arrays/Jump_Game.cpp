/*
Link : https://leetcode.com/problems/jump-game/
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/

class Solution {
public:
    int solve(vector<int> &nums,int current,vector<int> &memo)
    {
        if(current>=(nums.size()-1))
        {
            memo[nums.size()-1]=1;
            return 1;
        }
        if(memo[current]!=-1) return memo[current];
        for(int e=1;e<=nums[current];e++)
        {
            int val=current+e;
            if(val>=nums.size()) break;
            if(solve(nums,val,memo)) return memo[current]=1;
        }
        return memo[current]=0;
    }
    bool canJump(vector<int>& nums) {
       vector<int> memo(nums.size(),-1);
       solve(nums,0,memo);
       return memo[nums.size()-1]==1?true:false;
    }
};