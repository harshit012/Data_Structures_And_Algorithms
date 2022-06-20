/*
Link : https://leetcode.com/problems/minimum-window-substring/

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?

*/


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq_t;
        unordered_map<char,int> freq_s;
        for(int e=0;e<t.size();e++)
        {
            freq_t[t[e]]++;
        }
        int ub=0;
        int lb=0;
        int res_lb=0;
        int res_ub=0;
        int min_len=INT_MAX;
        int match_count=0;
        while(ub<s.size())
        {
            //aquiring characters
            while(ub<s.size())
            {
                char current=s[ub];
                if(freq_t.find(current)!=freq_t.end())
                {
                    freq_s[current]++;
                    if(freq_t[current]>=freq_s[current]) match_count++;
                }
                if(match_count==t.size()) break;
                ub++;
            }
            if(ub==s.size()) break;
            
            //releasing characters
            while(lb<=ub && match_count==t.size())
            {
                int dis=ub-lb+1;
                if(min_len>dis)
                {
                    min_len=dis;
                    res_lb=lb;
                    res_ub=ub;
                }
                char current=s[lb];
                if(freq_s.find(current)!=freq_s.end())
                {
                    freq_s[current]--;
                    if(freq_s[current]<freq_t[current]) match_count--;
                }
                lb++;
            }
            ub++;
        }
        if(min_len==INT_MAX) return "";
        string result="";
        while(res_lb<=res_ub)
        {
            result+=s[res_lb];
            res_lb++;
        }
        return result;
    }
};