class Solution:
    def __init__(self):
        pass

    def isSymmetric(self,num):
        # print(num)
        first = 0
        second = 0
        n=len(str(num))
        if (n&1) ==1:
            return False
        i=0
        while i<n//2:
            second+=num%10
            num//=10
            i+=1
        while i<n:
            first+=num%10
            num//=10
            i+=1
        # print(num, first, second)
        return first == second
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        res=0
        for i in range(low,high+1):
            if self.isSymmetric(i):
                res+=1
        return res
        
