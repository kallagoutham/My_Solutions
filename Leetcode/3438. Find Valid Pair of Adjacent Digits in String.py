class Solution:
    def findValidPair(self, s: str) -> str:
        f=Counter(s)
        for i in range(len(s)-1):
            if s[i]!=s[i+1] and f[s[i]]==int(s[i]) and f[s[i+1]]==int(s[i+1]):
                return s[i:i+2]
        return ""
