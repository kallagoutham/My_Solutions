class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        int res=1;
        int n=nums.size();
        LIS.resize(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    LIS[i] = max(LIS[i],1+LIS[j]);
                    res = max(res,LIS[i]);
                }
            }
        }
        return res;
    }
};
