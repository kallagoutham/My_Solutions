class Solution {
public:
    void permute(vector<int>& nums,int start,vector<vector<int>>& res){
        if(start==nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=start;i<nums.size();i++){
            if(s.count(nums[i])==0){
                s.insert(nums[i]);
                swap(nums[start],nums[i]);
                permute(nums,start+1,res);
                swap(nums[start],nums[i]);
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permute(nums,0,res);
        return res;
    }
};
