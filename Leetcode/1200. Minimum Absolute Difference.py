class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        res=[]
        arr.sort()
        mini=10000000
        for i in range(len(arr)-1):
            if(arr[i+1]-arr[i]==mini):
                res.append([arr[i],arr[i+1]])
            elif arr[i+1]-arr[i]<mini:
                mini=arr[i+1]-arr[i]
                res=[[arr[i],arr[i+1]]]
        return res
        
