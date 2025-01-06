class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n=len(boxes)
        l=[0]*n
        left=1 if boxes[0]=='1' else 0
        right=0
        for i in range(1,n):
            if boxes[i]=='1':
                l[0]+=i
                right+=1
        for i in range(1,n):
            l[i]=l[i-1]+left-right
            if boxes[i]=='1':
                left+=1
                right-=1
        return l
