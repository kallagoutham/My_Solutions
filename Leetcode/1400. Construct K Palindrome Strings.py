class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        freq=[0]*26
        if len(s)<k:
            return False
        for c in s:
            freq[ord(c)-ord('a')]+=1
        for i in range(26):
            if freq[i]&1 == 1:
                if k>0:
                    k-=1
                else:
                    return False
        return True
        
