class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        idx={}
        idx[nums[0]]=0
        for i in range(1,len(nums)):
            if target-nums[i] in idx:
                return [idx[target-nums[i]],i]
            else:
                idx[nums[i]]=i
        return []
        
