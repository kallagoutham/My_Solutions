class Solution:
    def getDigitSum(self,num):
        res=0
        while num>0:
            res+=num%10
            num//=10
        return res
    def maximumSum(self, nums: List[int]) -> int:
        m={}
        for i in nums:
            t=self.getDigitSum(i)
            if t not in m:
                m[t]=[-i]
            else:
                m[t].append(-i)
        res=-1
        for h in m.values():
            if len(h)>=2:
                heapq.heapify(h)
                largest=heapq.nsmallest(2,h)
                res=max(-sum(largest),res)
        return res
        
        
