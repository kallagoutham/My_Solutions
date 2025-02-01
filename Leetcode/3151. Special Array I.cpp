class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        int p=nums[0]&1;
        for(int i=1;i<n;i++){
            if((nums[i]&1) == p){
                return false;
            }else{
                p^=1;
            }
        }
        return true;
    }
};
