class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res=0;
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int end = 1; end < n; ++end) {
            if (nums[end] != nums[end - 1]) {
                dp[end] = dp[end - 1] + 1;
            }
        }
        for (int l : dp) {
            res += l;
        }
        return res;
    }
};
