class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,t=k,r=0,res=0;
        int n=nums.size();
        if(n==1){
            if(k==0){
                return nums[0];
            }else{
                return 1;
            }
        }
        while(l<n){
            while(t!=-1 && l<n){
                if(nums[l]==0){
                    t--;
                }
                if(t!=-1){
                    res=max(res,l-r+1);
                }
                l++;
                // cout<<t<<" "<<l<<" "<<r<<endl;
            }
            while(t==-1 && r<l){
                if(nums[r]==0){
                    if(t<k){
                        t++;
                    }
                }
                r++;
            }
        }
        return res;
    }
};
