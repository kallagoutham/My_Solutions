class Solution:
    def __init__(self):
        self.res=[]
    def isPalindrome(self,t):
        return t==t[::-1]
    def backtrack(self,s:str,temp:List[str],index):
        if index==len(s):
            self.res.append(temp[:])
            return
        t=""
        for i in range(index,len(s)):
            t+=s[i]
            if self.isPalindrome(t):
                temp.append(t)
                self.backtrack(s,temp,i+1)
                temp.pop()
        return 
    def partition(self, s: str) -> List[List[str]]:
        temp=[]
        self.backtrack(s,temp,0)
        return self.res
