/*
Link: https://leetcode.com/problems/valid-palindrome-ii/

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

class Solution {
public:
    bool check(string& s,int lb,int ub)
    {
        while(lb<ub)
        {
            if(s[lb]!=s[ub]) return false;
            lb++;
            ub--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int lb=0;
        int ub=s.size()-1;
        while(lb<ub)
        {
            if(s[lb]!=s[ub])
            {
                bool a=check(s,lb+1,ub);
                bool b=check(s,lb,ub-1);
                return a||b;
            }
            lb++;
            ub--;
        }
        return true;
    }
};