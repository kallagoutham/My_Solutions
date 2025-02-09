class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long res=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[i-nums[i]]++;
            res+=(m[i-nums[i]]-1);
        }
        return (n*(n-1))/2 - res;
    }
};
