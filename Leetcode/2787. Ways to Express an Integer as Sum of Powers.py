class Solution:
    def __init__(self):
        self.MOD = 1000000007
        self.dp=[[-1]*301 for i in range(301)]
    def ways(self,start,val,x):
        if val == 0:
            return 1
        if start > 300:
            return 0
        ans = self.dp[start][val]
        if ans != -1:
            return ans
        ans = 0
        if start**x <= val:
            ans = (ans + self.ways(start+1,val-(start**x),x)) % self.MOD
        ans = (ans + self.ways(start+1,val,x)) % self.MOD
        self.dp[start][val] = ans
        return ans

    def numberOfWays(self, n: int, x: int) -> int:
        return self.ways(1,n,x)
        
