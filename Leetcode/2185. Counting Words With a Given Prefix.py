class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        res=0
        n=len(pref)
        for word in words:
            if word[0:n]==pref:
                res+=1
        return res
        
