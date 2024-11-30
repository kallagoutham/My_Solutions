class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> res(2001,0);
        for(int i:nums){
            res[i+1000]++;
        }
        int l=0,r=2000;
        while(l<r){
            if(res[l]>0 && res[r]>0){
                return r-1000;
            }else{
                l++;r--;
            }
        }
        return -1;
    }
};
