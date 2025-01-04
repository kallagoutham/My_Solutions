class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:  
            return 0

        p1 = 0
        freq = {}
        n = len(s)
        res = 0

        for p2 in range(n):
            if s[p2] in freq and freq[s[p2]] > 0:
                while s[p1] != s[p2]:
                    freq[s[p1]] -= 1
                    p1 += 1
                p1 += 1  
            else:
                freq[s[p2]] = 1
                res = max(res,p2 - p1 + 1)

        return res
