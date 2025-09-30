# Brute Force
class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        while len(nums) != 1:
            t = []
            for i in range(len(nums)-1):
                t.append((nums[i]+nums[i+1])%10)
            nums=t
        return nums[0]


# Space optimised approach
class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        while len(nums) != 1:
            for i in range(len(nums)-1):
                nums[i] = (nums[i]+nums[i+1])%10
            nums.pop()
        return nums[0]
        
