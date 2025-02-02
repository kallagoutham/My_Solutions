class Solution:
    def check(self, nums: List[int]) -> bool:
        check = True
        n=len(nums)
        lm=0
        l=nums[0]
        r=0
        rm=nums[n-1]
        for i in range(1,n):
            if check==True:
                if nums[i-1]<=nums[i]:
                    pass
                else:
                    check=False
                    lm=nums[i-1]
                    r=nums[i]
                    i-=1
            if check==False:
                if nums[i-1]<=nums[i]:
                    pass
                else:
                    return False
        if check==False:
            if lm<rm or r>l or rm>l:
                return False
        return True
        
