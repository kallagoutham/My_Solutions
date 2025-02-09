class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        f={}
        c=0
        n=len(nums)
        for i in range(0,n):
            if (i-nums[i]) not in f:
                f[i-nums[i]]=1
            else:
                c+=f[i-nums[i]]
                f[i-nums[i]]+=1 
        return (n*(n-1))//2 - c
        
