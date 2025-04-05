class Solution:
    def __init__(self):
        self.ans=0
    def backtrack(self,xor,idx:int,nums:List[int]):
        if idx==len(nums):
            self.ans+=xor
            return
        #include
        self.backtrack(xor^nums[idx],idx+1,nums)
        #not include
        self.backtrack(xor,idx+1,nums)

    def subsetXORSum(self, nums: List[int]) -> int:
        xor=0
        self.backtrack(xor,0,nums)
        return self.ans
        
