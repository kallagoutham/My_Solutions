from collections import Counter
class Solution:
    def minimumLength(self, s: str) -> int:
        counter=Counter(s)
        res=0
        for j in counter:
            #print(i)
            if (counter[j]&1)==1:
                res+=1
            else:
                res+=2
        return res

        
