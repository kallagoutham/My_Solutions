class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l,r=0,0
        res=0
        n=len(nums)
        t=k
        while r<n:
            while t!=-1 and r<n:
                if nums[r]==0:
                    t-=1
                if t!=-1:
                    res=max(res,r-l+1)
                r+=1
            while t==-1 and l<r:
                if nums[l]==0:
                    t+=1
                l+=1
        return res

        
