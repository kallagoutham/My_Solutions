class Solution:
    def robotWithString(self, s: str) -> str:
        l = [0] * 26
        for i in s:
            l[ord(i) - ord('a')] += 1

        st = []
        res = ""
        for i in s:
            st.append(i)
            l[ord(i) - ord('a')] -= 1
            while st:
                top = st[-1]
                for j in range(26):
                    if l[j] != 0:
                        break
                else:
                    j = 26

                if ord(top) - ord('a') <= j:
                    res += st.pop()
                else:
                    break

        while st:
            res += st.pop()
        return res
2434. Using a Robot to Print the Lexicographically Smallest String
