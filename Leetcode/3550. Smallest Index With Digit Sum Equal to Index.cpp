class Solution {
public:
    int sod(int n){
        int t=0;
        while(n){
            t+=n%10;
            n/=10;
        }
        return t;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i==sod(nums[i])){
                return i;
            }
        }
        return -1;
    }
};
