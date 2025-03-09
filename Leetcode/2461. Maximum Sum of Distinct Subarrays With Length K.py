class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        freq = Counter(nums[:k])
        s = sum(nums[:k])
        res = 0
        n = len(nums)
        if len(freq) == k :
            res = max(res,s)
        for i in range(k,n):
            if nums[i] in freq:
                freq[nums[i]]+=1
            else:
                freq[nums[i]]=1
            s = s + nums[i] - nums[i-k]
            freq[nums[i-k]]-=1
            if freq[nums[i-k]]==0:
                del freq[nums[i-k]]
            if len(freq)==k:
                res = max(res,s)
        return res
