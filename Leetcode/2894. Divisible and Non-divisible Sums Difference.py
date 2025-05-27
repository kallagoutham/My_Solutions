class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        k=n//m
        print(k)
        return (n * (n + 1)) // 2 - 2 * (m * (k * (k + 1)) // 2)
        
