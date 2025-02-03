class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int t1=nums[0],t2=nums[0];
        int res1=1,res2=1,res=1;
        for(int i=1;i<n;i++){
            if(t1>nums[i]){
                res=max(++res1,res);
            }else{
                res1=1;
            }
            if(t2<nums[i]){
                res=max(res,++res2);
            }else{
                res2=1;
            }
            t1=nums[i];
            t2=nums[i];
        }
        return res;
    }
};
