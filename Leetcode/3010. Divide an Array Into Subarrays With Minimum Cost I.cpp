class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res=nums[0];
        nums.erase(nums.begin());
        sort(nums.begin(),nums.end());
        res+=nums[0]+nums[1];
        return res;
    }
};
