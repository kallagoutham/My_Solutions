#User function Template for python3
from collections import Counter
class Solution:

	
	def search(self,pat, txt):
	    # code here
        k=len(pat)
        freq=Counter(pat)
        count=len(freq)
        for j in range(k):
            if txt[j] not in freq:
                pass
            else:
                freq[txt[j]]-=1
                if freq[txt[j]]==0:
                    count-=1
        i=0
        n=len(txt)
        res=0
        while j<n:
           if count==0:
               res+=1
           j+=1
           if j<n and  txt[j] in freq:
               freq[txt[j]]-=1
               if freq[txt[j]]==0:
                   count-=1
           if txt[i] in freq:
               freq[txt[i]]+=1
               if freq[txt[i]]==1:
                   count+=1
           i+=1
        return res
	       
