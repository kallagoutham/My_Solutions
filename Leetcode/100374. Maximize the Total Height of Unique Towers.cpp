/*100374. Maximize the Total Height of Unique Towers

You are given an array maximumHeight, where maximumHeight[i] denotes the maximum height the ith tower can be assigned.

Your task is to assign a height to each tower so that:

The height of the ith tower is a positive integer and does not exceed maximumHeight[i].
No two towers have the same height.
Return the maximum possible total sum of the tower heights. If it's not possible to assign heights, return -1.

 

Example 1:

Input: maximumHeight = [2,3,4,3]

Output: 10

Explanation:

We can assign heights in the following way: [1, 2, 4, 3].

Example 2:

Input: maximumHeight = [15,10]

Output: 25

Explanation:

We can assign heights in the following way: [15, 10].*/


class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        long long res=0;
        sort(maximumHeight.begin(),maximumHeight.end());
        auto maxp=max_element(maximumHeight.begin(),maximumHeight.end());
        int mx=*maxp;
        for(int i=maximumHeight.size()-1;i>=0;i--){
            if(mx>maximumHeight[i]){
                mx=maximumHeight[i];
            }
            if(mx<=0){
                return -1;
            }
            res+=mx;            
            mx-=1;
        }
        return res;
    }
};
