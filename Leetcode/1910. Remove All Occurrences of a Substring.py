class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        # print(s[0:2])
        while s.find(part)!=-1:
            s=s[0:s.find(part)]+s[s.find(part)+len(part):]
            # print(s)
        return s
