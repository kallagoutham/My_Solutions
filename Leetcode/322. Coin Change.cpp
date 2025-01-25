class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,10000000);
        if(amount==0){return 0;}
        int n=coins.size();
        for(int i=0;i<n;i++){
            if(coins[i]<=amount){
                dp[coins[i]]=1;
            }
        }
        for(int coin:coins){
            for(int i=1;i<=amount;i++){
                if(i>=coin){
                    dp[i]=min(dp[i],1+dp[i-coin]);
                }
            }
        }
        return dp[amount]==10000000?-1:dp[amount];
    }
};
