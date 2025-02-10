class Solution:
    def clearDigits(self, s: str) -> str:
        st=deque()
        for ch in s:
            if ch<'a':
                if len(st)!=0:
                    st.pop()
            else:
                st.append(ch)
        res=""
        while st:
            res+=st[0]
            st.popleft()
        return res
        
