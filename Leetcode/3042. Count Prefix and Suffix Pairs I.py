class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        def isPrefixAndSuffix(str1,str2):
            return str2.find(str1)==0 and str2.find(str1,len(str2)-len(str1))!=-1
        n=len(words)
        res=0
        for i in range(0,n):
            for j in range(i+1,n):
                if isPrefixAndSuffix(words[i],words[j]):
                    res+=1
        return res
