class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        freq=Counter(nums)
        mf=0
        mini=float('inf')
        for i in freq:
            mf=max(mf,freq[i])
            mini=min(i,mini)
        if mini<k:
            return -1
        if k not in freq:
            return len(freq)
        return len(freq)-1
        
