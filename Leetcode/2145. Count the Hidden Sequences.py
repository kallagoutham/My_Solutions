class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        mini = 0
        maxi = 0
        cur = 0
        for d in differences:
            cur += d
            mini = min(mini, cur)
            maxi = max(maxi, cur)
        return max(0, (upper - maxi) - (lower - mini) + 1)
