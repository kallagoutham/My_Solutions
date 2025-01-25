class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp=[10000000]*(amount+1)
        if amount==0:
            return 0
        for coin in coins:
            if coin<=amount:
                dp[coin]=1
        for coin in coins:
            for i in range(amount+1):
                if coin<=i:
                    dp[i]=min(dp[i],1+dp[i-coin])
        if dp[amount]==10000000:
            return -1
        return dp[amount]
        
