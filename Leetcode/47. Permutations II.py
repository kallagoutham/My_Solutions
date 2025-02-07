class Solution:
    def permute(self,res :List[List[int]],start,nums):
        if start==len(nums):
            res.append(nums[:])
            return
        s=set()
        for i in range(start,len(nums)):
            if nums[i] not in s:
                s.add(nums[i])
                nums[i],nums[start]=nums[start],nums[i]
                self.permute(res,start+1,nums)
                nums[i],nums[start]=nums[start],nums[i]
        return 
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res=[]
        self.permute(res,0,nums)
        return res
        
