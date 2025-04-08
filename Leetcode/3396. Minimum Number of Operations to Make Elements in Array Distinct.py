class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n=len(nums)
        freq=set()
        duplicate=False
        for i in range(n-1,-1,-1):
            if nums[i] not in freq:
                freq.add(nums[i])
            else:
                duplicate=True
                break
        if (i==0) and (duplicate==False):
            return 0
        return (i+3)//3

        
