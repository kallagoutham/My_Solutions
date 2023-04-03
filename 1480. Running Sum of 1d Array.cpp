
//with linear space and time complexity i.e., s(c)=o(n) and t(c)=o(n)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            res.push_back(res[i-1]+nums[i]);
        }
        return res;
    }
};

-----------------------------------------------------------------------------------------------
//With constant space and time complexity of o(n)-linear 
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i-1]+nums[i];
        }
        return nums;
    }
};
