class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        res=[]
        freq=[0]*26
        mf=[0]*26
        for word in words2:
            freq=[0]*26
            for c in word:
                freq[ord(c)-ord('a')]+=1
            for i in range(26):
                mf[i]=max(mf[i],freq[i])
        for word in words1:
            freq=[0]*26
            isUniversal=True
            for c in word:
                freq[ord(c)-ord('a')]+=1
            for i in range(26):
                if freq[i]<mf[i]:
                    isUniversal=False
                    break
            if isUniversal:
                res.append(word)
        return res
            
        
