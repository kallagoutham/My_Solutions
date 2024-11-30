class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res=0;
        int xo = 0;
        for(int i:nums){
            xo^=i;
        }
        for(int i=0;i<32;i++){
            if((xo&(1<<i)) != (k&(1<<i))){res++;}
        }
        return res;
    }
};
