class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long> prefix(n);
        long s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            prefix[i]=s;
        }
        s=0;
        for(int i=0;i<n-1;i++){
            if((prefix[n-1]-prefix[i])<=(prefix[i])){
                s++;
            }
        }
        return s;
    }
};
