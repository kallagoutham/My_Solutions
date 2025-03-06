class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n=len(grid)
        freq={}
        res=[0]*2
        for i in range(n):
            for j in range(n):
                if grid[i][j] not in freq:
                    freq[grid[i][j]]=1
                else:
                    res[0]=grid[i][j]
        for i in range(1,n**2 + 1):
            if i not in freq:
                res[1]=i
                break
        return res
        
