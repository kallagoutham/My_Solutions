class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=INT_MIN;
        for(int i:nums){
            mx=max(i,mx);
        }
        int res=INT_MIN;
        int t=0;
        for(int i:nums){
            if(i==mx){
                t++;
                res=max(res,t);
            }else{
                t=0;
            }
        }
        return res;
    }
};
