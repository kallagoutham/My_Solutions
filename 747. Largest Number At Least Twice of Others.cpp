class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m1=INT_MIN,m2=INT_MIN;
        int idx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>m1){
                m1=nums[i];
                idx=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(m1!=nums[i]){
                m2=max(m2,nums[i]);
            }
        }
        return (m1>=2*m2)?idx:-1;
    }
};
