class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int ei=0,oi=1;
        for(int num:nums){
            if(num&1){
                res[oi]=num;
                oi+=2;
            }else{
                res[ei]=num;
                ei+=2;
            }
        }
        return res;
    }
};
