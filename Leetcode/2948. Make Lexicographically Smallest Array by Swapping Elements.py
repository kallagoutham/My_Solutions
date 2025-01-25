class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n=len(nums)
        mnums=[]
        for i in range(n):
            mnums.append([nums[i],i])
        mnums.sort()
        i,j=0,0
        while i<n:
            j=i+1
            while j<n and mnums[j][0] - mnums[j-1][0]<=limit:
                j+=1
            idx=[]
            for l in range(i,j):
                idx.append(mnums[l][1])
            idx.sort()
            p=0
            for l in range(i,j):
                nums[idx[p]]=mnums[l][0]
                p+=1
            i=j
        return nums
        
