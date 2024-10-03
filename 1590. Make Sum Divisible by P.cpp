class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long totalSum=0;
        for (int i:nums) {
            totalSum+=i;
        }
        ;
        if(totalSum%p==0) {
            return 0;
        }
        unordered_map<long, int> modMap;
        modMap[0] =-1; 
        long prefixSum =0;
        int minLength = n; 
        for (int i=0;i<n;i++) {
            prefixSum+=nums[i];
            long currentMod=prefixSum % p;
            long targetMod=(currentMod-(totalSum%p)+p)%p;
            if (modMap.find(targetMod)!=modMap.end()) {
                minLength=min(minLength,i-modMap[targetMod]);
            }
            modMap[currentMod]=i;
        }
        return minLength==n?-1: minLength;
    }
};
