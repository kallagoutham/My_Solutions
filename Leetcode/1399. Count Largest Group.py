class Solution:
    def countLargestGroup(self, n: int) -> int:
        def sumOfDigits(num):
            s=0
            while num>0:
                s += num%10
                num //=10
            return s
        freq={}
        maxFrequency=-float('inf')
        for i in range(1,n+1):
            # t=(i-1)%9 #this only works if we want to reduce to one digit
            t = sumOfDigits(i)
            if t in freq:
                freq[t] = freq[t] + 1
            else:
                freq[t] = 1
            maxFrequency = max(maxFrequency,freq[t])
        res=0
        for i in freq:
            if freq[i] == maxFrequency:
                res+=1
        return res
        
