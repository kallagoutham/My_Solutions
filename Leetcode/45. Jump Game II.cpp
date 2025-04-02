class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),l=0,r=0;
        int jumps=0;
        while(r<n-1){
            int far=INT_MIN;
            for(int i=l;i<r+1;i++){
                far=max(i+nums[i],far);
            }
            l=r+1;
            jumps++;
            r=far;
        }
        return jumps;
    }
};
