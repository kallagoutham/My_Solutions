class Solution {
public:
    int arraySign(vector<int>& nums) {
        if(find(nums.begin(),nums.end(),0)!=nums.end()){
            return 0;
        }
        int res=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                res*=-1;
            }
        }
        return res;
    }
};
