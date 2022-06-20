/*
Link : https://leetcode.com/problems/valid-parentheses/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

class Solution {
public:
    bool isValid(string s) {
        list<char> stk;
        unordered_map<char,char> store;
        store['[']=']';
        store['{']='}';
        store['(']=')';
        for(int e=0;e<s.size();e++)
        {
            if(stk.size()==0)
            {
                if(s[e]=='(' || s[e]=='{' || s[e]=='[') stk.push_back(s[e]);
                else return false;
            }
            else
            {
                char top=stk.back();
                if(s[e]=='(' || s[e]=='{' || s[e]=='[') stk.push_back(s[e]);
                else
                {
                    if(store[top]==s[e]) stk.pop_back();
                    else return false;
                }
            }
        }
        if(stk.size()==0) return true;
        return false;
    }
};