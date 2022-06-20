/*
Link : https://leetcode.com/problems/reverse-words-in-a-string/submissions/

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

*/

class Solution {
public:
    string reverseWords(string s) {
          vector<string>v;
        string temp="",ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(s[i]==' ' && temp.size()){
                v.push_back(temp);
                temp.clear();
            }
        }
        if(temp.size()) v.push_back(temp);
        for(int i=v.size()-1;i>=1;i--){
            ans+=v[i]+" ";
        }
        ans+=v[0];
        return ans;
       
    }
};