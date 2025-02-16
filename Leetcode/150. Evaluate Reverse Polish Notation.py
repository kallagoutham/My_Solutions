class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st=deque()
        for c in tokens:
            if c == "+" or c == "-" or c == "/" or c == "*":
                b = int(st.pop())  
                a = int(st.pop())  
                exp = f"{a} {c} {b}"  
                st.append(eval(exp))  
            else:
                st.append(c)
        return int(st[-1])
