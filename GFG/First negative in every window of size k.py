class Solution:
    def FirstNegativeInteger(self, arr, k): 
        l=[]
        res=[]
        i=0
        for j in range(k):
            if arr[j]<0:
                l.append(arr[j])
        n=len(arr)
        while j<n:
            if len(l)>0:
                res.append(l[0])
                if arr[i]==l[0]:
                    l.pop(0)
            else:
                res.append(0)
            j+=1
            if j<n and arr[j]<0:
                l.append(arr[j])
            i+=1
        return res