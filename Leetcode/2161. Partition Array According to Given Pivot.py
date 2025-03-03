class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        l=[]
        p=[]
        r=[]
        for i in nums:
            if i < pivot:
                l.append(i)
            elif i > pivot:
                r.append(i)
            else:
                p.append(i)
        return l+p+r
