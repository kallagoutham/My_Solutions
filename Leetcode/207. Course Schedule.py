from collections import deque
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        d=[0]*numCourses
        adj = [[] for _ in range(numCourses)]
        for i in prerequisites:
            adj[i[1]].append(i[0])
            d[i[0]]+=1
        q=deque()
        for i in range(numCourses):
            if d[i]==0:
                q.append(i)
        while q:
            t=q[0]
            q.popleft()
            for i in adj[t]:
                d[i]-=1
                if(d[i]==0):
                    q.append(i)
        for i in d:
            if i!=0:
                return False
        return True
