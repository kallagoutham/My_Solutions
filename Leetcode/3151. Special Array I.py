class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        p=nums[0] & 1
        n=len(nums)
        for i in range(1,n):
            if (nums[i] & 1) == p:
                return False
            else:
                p=p ^ 1
        return True
        
