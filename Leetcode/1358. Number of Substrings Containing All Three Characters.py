class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        res = 0
        freq = {'a': 0, 'b': 0, 'c': 0}
        n = len(s)
        i = 0
        for j in range(n):
            freq[s[j]] += 1
            while freq['a'] > 0 and freq['b'] > 0 and freq['c'] > 0:
                res += (n - j)
                freq[s[i]] -= 1
                i += 1
        return res
