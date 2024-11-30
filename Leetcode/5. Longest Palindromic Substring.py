class Solution:
    def longestPalindrome(self, s: str) -> str:
        m=0
        res=""
        for i in range(len(s)):
            l=i
            r=i+1
            
            while(l>=0 and r<len(s) and s[l]==s[r]):
                if((r-l+1) > m):
                    res=s[l:r+1]
                    m=r-l+1
                l-=1
                r+=1
            l,r=i,i
            while(l>=0 and r<len(s) and s[l]==s[r]):
                if((r-l+1) > m):
                    res=s[l:r+1]
                    m=r-l+1
                l-=1
                r+=1
        return res
            
            
        
        
