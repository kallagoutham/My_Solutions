class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n=len(nums)
        t1,t2=nums[0],nums[0]
        res1=1
        res2=1
        res=1
        for i in range(1,n):
            if t1>nums[i]:
                res1+=1
                res=max(res,res1)
            else:
                res1=1
            if t2<nums[i]:
                res2+=1
                res=max(res,res2)
            else:
                res2=1
            t1,t2=nums[i],nums[i]
        return res
