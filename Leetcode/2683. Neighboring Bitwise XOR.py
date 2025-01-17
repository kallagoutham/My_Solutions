class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        xr=0
        for i in derived:
            xr^=i
        if xr==1:
            return False
        return True
        
