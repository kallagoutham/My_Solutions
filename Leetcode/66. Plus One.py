class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        m=""
        for i  in digits:
            m+=str(i)
        k=int(m)
        k=k+1
        m=str(k)
        l=[]
        for i in m:
            l.append(i)
        return l
            
