class Solution:
    def isValid(self,sq,pos,val,target)->bool:
        if pos==len(sq):
            return val==target
        i=0
        while i+pos<len(sq):
            c=int(sq[pos:pos+i+1])
            if self.isValid(sq,pos+1+i,val+c,target):
                return True
            i+=1
        return False
    def punishmentNumber(self, n: int) -> int:
        res=1
        for i in range(2,n+1):
            if self.isValid(str(i**2),0,0,i):
                res+=(i**2)
        return res
        
