class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        maxIdx = 0
        for i in range(n):
            if i>maxIdx:
                return False
            else:
                maxIdx=max(i+nums[i],maxIdx)
        return True
        
