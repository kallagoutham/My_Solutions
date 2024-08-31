//Using binary search that if nums[i] then setting the target sum to -nums[i] and performing binary search

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};



//Using Recursion

class Solution {
public:
    set<vector<int>> res;
    void generateThreeSumTriplets(vector<int>& nums,int length,int sum,vector<int>& t,int idx){
        if(length==3 && sum==0){
            vector<int> temp=t;
            sort(temp.begin(),temp.end());
            res.insert(temp);
            return;
        }
        if(length>3 || idx>=nums.size()){
            return;
        }
        t.push_back(nums[idx]);
        generateThreeSumTriplets(nums,length+1,sum+nums[idx],t,idx+1);
        t.pop_back();
        generateThreeSumTriplets(nums,length,sum,t,idx+1);
        return;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> t;
        generateThreeSumTriplets(nums,0,0,t,0);
        vector<vector<int>> r(res.begin(),res.end());
        return r;
    }
};
