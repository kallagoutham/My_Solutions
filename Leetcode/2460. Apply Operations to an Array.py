class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        res=[]
        n=len(nums)
        for i in range(0,n-1):
            if nums[i]==nums[i+1] and nums[i]!=0:
                res.append(nums[i]*2)
                nums[i+1]=0
            else:
                if nums[i]!=0:
                    res.append(nums[i])
        if nums[n-1]!=0:
            res.append(nums[n-1])
        res=res+[0]*(n-len(res))
        return res
