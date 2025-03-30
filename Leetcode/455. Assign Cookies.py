class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        l,r=0,0
        m,n=len(g),len(s)
        if m==0 or n==0:
            return 0
        while r<n and l<m:
            if g[l]<=s[r]:
                l+=1
            r+=1
        return l
        
