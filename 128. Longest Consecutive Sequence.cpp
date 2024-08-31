class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0;
        if(nums.size()==0){return 0;}
        if(nums.size()==1){return 1;}
        sort(nums.begin(),nums.end());
        int t=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]==nums[i-1]){
                res=max(t,res);
                continue;
            }
            if(nums[i]==nums[i-1]+1){
                t++;
            }else{
                t=1;
            }
            res=max(t,res);
        }
        return res;
    }
};
