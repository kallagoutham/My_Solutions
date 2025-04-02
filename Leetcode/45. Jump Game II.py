class Solution:
    def jump(self, nums: List[int]) -> int:
        n,l,r=len(nums),0,0
        jumps = 0
        while r<n-1:
            far=0
            for i in range(l,r+1):
                far=max(nums[i]+i,far)
            l=r+1
            jumps=jumps+1
            r=far
        return jumps
        
