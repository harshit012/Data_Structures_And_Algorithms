/*
Link : https://leetcode.com/problems/subarray-sum-equals-k/

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int n = nums.size();
        unordered_map<int, int>m;
        m[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];     
            int target = sum-k;
            if(m.find(target)!=m.end()) ans += m[target]; 
            m[sum]++;
        }
        return ans;
    }
};