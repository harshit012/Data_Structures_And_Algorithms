/*
Link: https://leetcode.com/problems/sort-colors/
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 
Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/

class Solution {
public:
    void sortColors(vector<int>& x) {

int ri,ci,lci,rci,e,f,g,swi;
e=0;
int n=x.size();
while(e<=n-1)
{
ci=e;
ri=(ci-1)/2;
while(ci>0)
{
if(x[ci]>x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
}
ci=ri;
ri=(ci-1)/2;
}
e++;
}

e=n-1;
while(e>0)
{
g=x[0];
x[0]=x[e];
x[e]=g;
e--;
ri=0;
while(ri<e)
{
lci=(ri*2)+1;
rci=lci+1;
if(lci>e) break;
if(rci>e) swi=lci;
else
{
if(x[lci]>x[rci]) swi=lci;
else swi=rci;
}
if(x[ri]<x[swi])
{
g=x[ri];
x[ri]=x[swi];
x[swi]=g;
ri=swi;
}
else break;
}
}
}
};