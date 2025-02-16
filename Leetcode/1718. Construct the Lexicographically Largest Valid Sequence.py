class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        # Array size is 2*n-1
        ans = [0]*(2*n-1)
        used = [False]*(n+1)  # Track used numbers
        
        def canPlace(pos, num):
            # Check if we can place num at pos
            if pos + num >= len(ans):  # Out of bounds
                return False
            if ans[pos] != 0 or ans[pos + num] != 0:  # Already filled
                return False
            return True
        
        def dfs(pos):
            # If we've filled all positions
            if pos >= len(ans):
                return True
                
            # If current position is already filled, move to next
            if ans[pos] != 0:
                return dfs(pos + 1)
            
            # Try placing numbers from largest to smallest
            for i in range(n, 0, -1):
                if used[i]:
                    continue
                    
                # For number 1, we only place it once
                if i == 1:
                    if canPlace(pos, 0):  # Just check current position
                        ans[pos] = 1
                        used[1] = True
                        if dfs(pos + 1):
                            return True
                        ans[pos] = 0
                        used[1] = False
                else:
                    # For other numbers, we need to place them twice
                    if canPlace(pos, i):
                        ans[pos] = i
                        ans[pos + i] = i
                        used[i] = True
                        if dfs(pos + 1):
                            return True
                        ans[pos] = 0
                        ans[pos + i] = 0
                        used[i] = False
                        
            return False
            
        dfs(0)
        return ans
