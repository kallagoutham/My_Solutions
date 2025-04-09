class Solution:
    def solve(self, bt):
        bt.sort()
        waitTime,t=0,0
        for i in bt:
            waitTime+=t
            t+=i
        return waitTime//len(bt)
