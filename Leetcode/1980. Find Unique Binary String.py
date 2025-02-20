class Solution:
    def __init__(self):
        self.l=set()
    def generate(self,n,le,s):
        if len(s)==n:
            self.l.add(s)
            return
        self.generate(n,le+1,s+"0")
        self.generate(n,le+1,s+"1")
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n=len(nums)
        self.generate(n,0,"")
        for i in self.l:
            if i not in nums:
                return i
        return ""
