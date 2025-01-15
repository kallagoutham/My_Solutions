class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        s1,s2=bin(num1).count('1'),bin(num2).count('1')
        res=num1
        for i in range(32):
            if s1>s2 and (1<<i)&num1>0:
                res^=(1<<i)
                s1-=1
            if s1<s2 and (1<<i)&num1==0:
                res^=(1<<i)
                s1+=1
        return res
