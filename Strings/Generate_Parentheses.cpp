/*
Link : https://leetcode.com/problems/generate-parentheses/
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    void solve(string data,int start,int end,vector<string> &result)
    {
        if(start==0 && end==0)
        {
            result.push_back(data);
        }
        if(start==0)
        {
            while(end--)
            {
                data+=")";
            }
            result.push_back(data);
        }
        else
        {
            solve(data+"(",start-1,end,result);
            if(start<end) solve(data+")",start,end-1,result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve("",n,n,result);
        return result;
    }
};
