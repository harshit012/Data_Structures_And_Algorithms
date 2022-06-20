/*
Link : https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.


*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=0;
        list<char> store;
        for(int e=0;e<strs[0].size();e++)
        {
            store.push_back(strs[0][e]);
            len=e;
        }
        for(int s=1;s<strs.size();s++)
        {
            int index=0;
            for(int ccc:store)
            {
                if(index>len) break;
                if(index==strs[s].size())
                {
                    len=index-1;
                    break;
                }
                if(strs[s][index]!=ccc)
                {
                    len=index-1;
                    break;
                }
                index++;
            }
            if(len==-1) break;
        }
        if(len==-1) return "";
        string result="";
        int ind=0;
        for(char cc:store)
        {
            if(ind>len) break;
            result+=cc;
            ind++;
        }
        return result;
    }
};