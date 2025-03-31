class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        if k == 1:
            return 0  
        n = len(weights)
        l = [weights[i] + weights[i+1] for i in range(n-1)]  
        l.sort()
        return sum(l[-(k-1):]) - sum(l[:(k-1)])
