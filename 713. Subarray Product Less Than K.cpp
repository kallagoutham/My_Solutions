class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p1=0,p2=0,prod=nums[0],res=0,n=nums.size();
        while(p1<n && p2<n){
            if(prod<k){
                p2++;
                if(p2>=p1){
                    res+=(p2-p1);
                }
                if(p2<n){prod*=nums[p2];}
            }else{
                prod=(prod/nums[p1])>0?(prod/nums[p1]):1;
                p1++;
            }
        }
        return res;
    }
};
