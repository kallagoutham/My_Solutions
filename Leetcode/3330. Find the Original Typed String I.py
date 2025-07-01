class Solution:
    def possibleStringCount(self, word: str) -> int:
        c=word[0]
        res=1
        for i in range(1,len(word)):
            if c==word[i]:
                res+=1
            else:
                c=word[i]
        return res
