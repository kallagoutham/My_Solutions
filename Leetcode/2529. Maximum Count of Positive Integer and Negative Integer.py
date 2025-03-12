class Solution:
    def maximumCount(self, nums: list[int]) -> int:
        n = len(nums)
        l, h = 0, n - 1
        neg = -1
        while l <= h:
            m = (l + h) // 2
            if nums[m] < 0:
                neg = m  
                l = m + 1  
            else:
                h = m - 1  
        l, h = 0, n - 1
        pos = n  
        while l <= h:
            m = (l + h) // 2
            if nums[m] > 0:
                pos = m  
                h = m - 1  
            else:
                l = m + 1  
        neg_count = neg + 1  
        pos_count = n - pos  
        
        return max(neg_count, pos_count)
