class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int dp[3] = {0,0,0};
        for(vector<int> cost:costs){
            int dp0 = cost[0] + min(dp[1] , dp[2]);
            int dp1 = cost[1] + min(dp[0] , dp[2]);
            int dp2 = cost[2] + min(dp[0] , dp[1]);
            dp[0] = dp0;
            dp[1] = dp1;
            dp[2] = dp2;
        }
        return min(dp[2],min(dp[0],dp[1]));
    }
};
