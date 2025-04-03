class Solution:    
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.
    def minimumPlatform(self,arr,dep):
        # code here
        arr.sort()
        dep.sort()
        i,j=0,0
        n=len(arr)
        minimumPlatforms=-float('inf')
        cnt=0
        while i<n:
            if arr[i]<=dep[j]:
                cnt+=1
                i+=1
            else:
                cnt-=1
                j+=1
            minimumPlatforms=max(cnt,minimumPlatforms)
        return minimumPlatforms
            
