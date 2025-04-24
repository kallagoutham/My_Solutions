class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        total_unique = len(set(nums))
        count = 0
        n = len(nums)

        for i in range(n):
            freq = defaultdict(int)
            unique = 0
            for j in range(i, n):
                if freq[nums[j]] == 0:
                    unique += 1
                freq[nums[j]] += 1
                if unique == total_unique:
                    count += 1
        return count
