class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        res = 0
        for i in nums:
            if len(str(i)) & 1 == 0 :
                res += 1
        return res
        
