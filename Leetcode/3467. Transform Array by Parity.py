class Solution:
    def transformArray(self, nums: List[int]) -> List[int]:
        o,e=0,0
        for i in nums:
            if (i&1) == 1:
                o+=1
            else:
                e+=1
        return [0]*e+[1]*o
