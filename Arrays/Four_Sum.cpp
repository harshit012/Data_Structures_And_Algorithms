/*
Link: https://leetcode.com/problems/4sum/
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)
            return {};
        vector <vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int target1 = target - nums[i];
            for(int j=i+1; j<nums.size(); j++){
                int low = j+1, high = nums.size()-1, target2 = target1-nums[j];
                while(low<high){
                    if(nums[low]+nums[high] == target2){
                        vector <int> r = {nums[i], nums[j], nums[low], nums[high]};
                        result.push_back(r);
                        while(nums[low]==r[2] && low<high)
                            low++;
                        
                        while(nums[high]==r[3] && low<high)
                            high--;
                    }
                    else if(nums[low]+nums[high] < target2)
                        low++;
                    else
                        high--;
                }
                while(j+1< nums.size() && nums[j+1] == nums[j]) ++j;
            }
            while (i+1< nums.size() && nums[i+1] == nums[i]) ++i;
        }
        return result;
    }
};