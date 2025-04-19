class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int min = lower - nums[i] ,max= upper - nums[i];
            auto high=upper_bound(nums.begin()+i+1,nums.end(),max);
            auto low=lower_bound(nums.begin()+i+1,nums.end(),min);
            res+=(high-low);
        }
        return res;
    }
};
