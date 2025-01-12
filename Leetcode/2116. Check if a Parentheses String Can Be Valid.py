class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        o = 0
        f = 0
        n = len(s)
        if n % 2 == 1:
            return False
        for i in range(n):
            if locked[i] == '1':
                if s[i] == '(':
                    o += 1
                else:
                    o -= 1
            else:
                f += 1
            if o + f < 0:
                return False
        o = 0
        f = 0
        for i in range(n - 1, -1, -1):
            if locked[i] == '1':
                if s[i] == ')':
                    o += 1
                else:
                    o -= 1
            else:
                f += 1
            if o + f < 0:
                return False
        return True
