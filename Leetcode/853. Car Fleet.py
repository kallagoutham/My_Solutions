class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pairs=[[p,s] for p,s in zip(position,speed)]
        pairs.sort(reverse=True)
        st=[]
        for p,s in pairs:
            st.append((target-p)/s)
            if len(st)>=2 and st[-1]<=st[-2]:
                st.pop()
        return len(st)
