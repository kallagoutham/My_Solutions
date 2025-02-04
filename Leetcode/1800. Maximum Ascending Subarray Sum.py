class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        res=nums[0]
        n=len(nums)
        prev=nums[0]
        s=nums[0]
        for i in range(1,n):
            if nums[i]>prev:
                s+=nums[i]
                res=max(s,res)
            else:
                s=nums[i]
                res=max(s,res)
            prev=nums[i]
        return res
        
