class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        int k=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]  &&  nums[i]!=0){
                res[k++]=nums[i]*2;
                nums[i+1]=0;
            }else{
                if(nums[i]!=0){
                    res[k++]=nums[i];
                }
            }
        }
        if(nums[n-1]!=0){
            res[k++]=nums[n-1];
        }
        return res;
    }
};
