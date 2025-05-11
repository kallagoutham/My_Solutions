class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        n = 0
        for i in arr:
            if i & 1 == 0:
                n = 0
            else:
                n += 1
                if n == 3:
                    return True
        return False
        
