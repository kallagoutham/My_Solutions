class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> um;
    int n=nums.size();
        vector<int> v;
        for(int i=0; i<n; i++){
            if(um.find(target-nums[i])!= um.end()){
                v.push_back(i);
                v.push_back(um[target-nums[i]]);
                break;
            }
            um[nums[i]]= i;
        }
        return v;
    }
};
