class Solution {
public:
    int res=0;
    void backtrack(vector<int>& nums,int target,int sum,int idx){
        if(idx==nums.size()){
            if(target==sum){
                res++;
            }
            return;
        }
        backtrack(nums,target,sum-nums[idx],idx+1);
        backtrack(nums,target,sum+nums[idx],idx+1);
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums,target,0,0);
        return res;
    }
};
