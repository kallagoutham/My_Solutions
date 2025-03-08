class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        i=0
        j=k-1
        n=len(blocks)
        count=blocks[:k].count('W')
        res=count
        # print(j,n-1)
        while j<n-1:
            j+=1
            if blocks[j]=='W':
                count+=1
            if blocks[i]=='W':
                count-=1
            i+=1
            # print(count)
            res=min(count,res)
        return res
        
