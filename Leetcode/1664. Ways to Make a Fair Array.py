class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        res=0
        n=len(nums)
        prefix_even=[0]*(n+1)
        prefix_odd=[0]*(n+1)
        for i in range(n):
            prefix_even[i+1]=prefix_even[i]
            prefix_odd[i+1]=prefix_odd[i]
            if i&1==0:
                prefix_even[i+1]=prefix_even[i]+nums[i]
            else:
                prefix_odd[i+1]=prefix_odd[i]+nums[i]
        for i in range(n):
            if prefix_even[i]+(prefix_odd[n]-prefix_odd[i+1]) == prefix_odd[i]+(prefix_even[n]-prefix_even[i+1]):
                res+=1
        return res


        
