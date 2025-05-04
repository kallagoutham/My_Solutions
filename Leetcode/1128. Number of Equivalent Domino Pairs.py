class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        f = {}
        res = 0
        for i in dominoes:
            n = tuple(sorted(i))
            if n in f:
                f[n] += 1
            else:
                f[n] = 1
        for i in f:
            res += (f[i] * (f[i] - 1)) // 2
        return res

        
