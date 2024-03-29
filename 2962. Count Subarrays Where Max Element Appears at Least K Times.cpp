class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res=0;
        int p1=0,p2=0;
        int n=nums.size();
        int mx=INT_MIN;
        for(int i:nums){
            mx=max(i,mx);
        }
        while(p1<n){
            if(nums[p1++]==mx){k--;}
            while(k==0){
                if(nums[p2++]==mx){k++;}
            }
            res+=p2;
        }
        return res;
    }
};
