class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        st=set()
        freq={}
        for c in s:
            if c not in freq:
                freq[c]=1
            else:
                freq[c]+=1
        pr={}
        for c in s:
            freq[c]-=1
            for char in freq:
                if char in pr and pr[char]>=1 and freq[char]>=1:
                    st.add(char+c+char)
            if c in pr:
                pr[c]+=1
            else:
                pr[c]=1
        return len(st)
        
        
