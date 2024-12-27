class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int res=INT_MIN;
        vector<int> dp(n);
        dp[0]=values[0];
        for(int i=1;i<n;i++){
            int t=values[i]-i;
            res=max(res,dp[i-1]+t);
            t=values[i]+i;
            dp[i]=max(dp[i-1],t);
        }
        return res;
    }
};
