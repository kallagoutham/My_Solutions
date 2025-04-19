class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        res=0
        n=len(nums)
        if n==1:
            return 0
        for i in range(n):
            minimum = lower-nums[i]
            maximum = upper-nums[i]
            low = bisect_left(nums, minimum, i + 1)
            high = bisect_right(nums, maximum, i + 1)
            res += high - low
        return res
        
