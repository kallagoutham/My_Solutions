class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res=0;
        int i=0,n=nums.size();
        while(i<n){
            int j=0;
            int c=0;
            while(j<32){
                if((i&(1<<j))!=0){c++;}
                j++;
            }  
            if(c==k){res+=nums[i];}
            i++;
        }
        return res;
    }
};
