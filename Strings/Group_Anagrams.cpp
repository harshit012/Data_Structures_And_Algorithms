/*
Link : https://leetcode.com/problems/group-anagrams/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,list<string>> store;
        vector<vector<string>> result;
        for(int e=0;e<strs.size();e++)
        {
            string data=strs[e];
            sort(data.begin(),data.end());
            store[data].push_back(strs[e]);
        }
        for(pair<string,list<string>> pp:store)
        {
            vector<string> subList;
            for(string data:pp.second) subList.push_back(data);
            result.push_back(subList);
        }
        return result;
    }
};